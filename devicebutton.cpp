#include "devicebutton.h"
#include <QTabWidget>
#include <QPixmap>
#include <QBitmap>
#include <QGridLayout>
#include <QMessageBox>
#include <QMenu>
#include <stdio.h>
#include <QDebug>

DeviceButton::DeviceButton(NodeDetail* detail, NodeSetting setting):
    m_detail(detail),
    m_setting(setting)
{
    init();
    connect(this, SIGNAL(clicked(bool)), this, SLOT(onclick()));
}

void DeviceButton::setStatus(DeviceStatus status)
{
    switch(status){
    case OK:
        m_status->setStyleSheet(ok_style_sheet);
        break;

    case FAULT:
        m_status->setStyleSheet(fault_style_sheet);
        break;

    case DISCONNECT:
        m_status->setStyleSheet(disconnect_style_sheet);
        break;
    }
}

/*
QSize DeviceButton::sizeHint() const{
    return QSize(160, 120);
}
*/

void DeviceButton::onclick()
{
    //m_detail->setText(this->text());
}

void DeviceButton::init()
{
    QGridLayout* layout = new QGridLayout(this);

    m_address = new QLabel;
    m_description = new QLabel;
    m_status = new QLabel;

    m_status->setFixedSize(32, 32);
    m_address->setStyleSheet("QLabel{font-size:16px; color:white;}");

    layout->addWidget(m_address, 0, 0, 1, 2);
    layout->addWidget(m_status, 2, 4, 1, 1);
    layout->addWidget(m_description, 3, 0, 1, 2);

    m_address->setText(m_setting.ip);
    m_description->setText(m_setting.desc);


    setObjectName("dev-btn");
    setStyleSheet("QPushButton#dev-btn{border-image: url(:/res/panel.png)}");

    m_socket = new QTcpSocket(this);
    qDebug() << m_setting.ip << ", " << m_setting.port.toUShort();
    m_socket->connectToHost(QHostAddress(m_setting.ip), m_setting.port.toUShort());

    connect(m_socket, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(onReadData()));
    connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(onSocketError(QAbstractSocket::SocketError)));

    setFixedSize(180, 120);
    setStatus(DISCONNECT);

    m_reconnectAction = new QAction(QString::fromUtf8("重连"),this);
    connect(m_reconnectAction, SIGNAL(triggered(bool)), this, SLOT(onReconnAction()));

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    m_timer->setInterval(1000);
}

void DeviceButton::mouseDoubleClickEvent(QMouseEvent *e)
{
    QMessageBox::about(this, "ID", this->id());
}

void DeviceButton::contextMenuEvent(QContextMenuEvent *e)
{
    QMenu *menu = new QMenu;

    menu->addAction(m_reconnectAction);
    menu->exec(e->globalPos());

    delete menu;
}

void DeviceButton::onConnected()
{
    qDebug() << "connected!";

    m_timer->start();

    setStatus(OK);
}

void DeviceButton::onTimeout()
{
    int n = m_socket->write(modbus_command, sizeof(modbus_command));
    qDebug() << "send " << n << " byte.";
}

void DeviceButton::onReadData()
{
    unsigned char data[128];
    memset(data, 0, sizeof(data));
    int n = m_socket->read((char*)data, sizeof(data));
    if(n < 41){
        m_detail->errorLog(id(), QString("read %1 bytes, less 41 bytes.").arg(n));
        return;
    }

    QString hexdata;
    char hex[3] = {0,0,0};
    for(int i=0; i<n; i++){
        sprintf(hex, " %02X ", data[i]);
        hexdata += QString(hex);
    }
    hexdata += QString("\n");
    m_detail->errorLog(id(), hexdata);

    GYData gy_data;
    gy_data.ac_v = ((unsigned int)data[9])*256 + (unsigned int)data[10];
    gy_data.dc_v = float(((unsigned int)data[15])*256 + (unsigned int)data[16]) / 10.0;
    gy_data.dc_i = float(((unsigned int)data[25])*256 + (unsigned int)data[26]) / 10.0;
    gy_data.faultBit1 = ((unsigned int)data[37])*256 + (unsigned int)data[38];
    gy_data.faultBit2 = ((unsigned int)data[39])*256 + (unsigned int)data[40];

    if(this->hasFocus()){
        m_detail->showGYData(this->id(), gy_data);
    }
}

void DeviceButton::onSocketError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        setStatus(DISCONNECT);
        m_detail->errorLog(id(), "lost connection...");
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("Network error"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        setStatus(DISCONNECT);
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("Network error"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the fortune server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        setStatus(DISCONNECT);
        break;
    default:
        setStatus(DISCONNECT);
        QMessageBox::information(this, tr("Network error"),
                                 tr("The following error occurred: %1.")
                                 .arg(m_socket->errorString()));
    }
}

void DeviceButton::onReconnAction()
{
    m_socket->abort();
    m_socket->connectToHost(QHostAddress(m_setting.ip), m_setting.port.toUShort());
}




