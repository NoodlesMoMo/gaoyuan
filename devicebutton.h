#ifndef DEVICEBUTTON_H
#define DEVICEBUTTON_H

#include <QPushButton>
#include <QString>
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QAction>
#include <QTimer>
#include <QContextMenuEvent>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>

#include "nodedetail.h"
#include "devnodesetting.h"
#include "gydata.h"

const QString ok_style_sheet = QString("QLabel{border-image: url(:/res/green.png)}");
const QString fault_style_sheet = QString("QLabel{border-image: url(:/res/red.png)}");
const QString disconnect_style_sheet = QString("QLabel{border-image: url(:/res/yellow.png)}");

const char modbus_command[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x06,
    0x01, 0x03, 0x20, 0x00, 0x00, 0x14
};

class DeviceButton : public QPushButton
{
    Q_OBJECT

public:
    enum DeviceStatus{OK, FAULT, DISCONNECT};

public:
    DeviceButton(NodeDetail* detail, NodeSetting);

    void setStatus(DeviceStatus status);

    const QString id() { return m_setting.id(); }
    const QString ip() { return m_setting.ip; }
    const QString port() { return m_setting.port; }
    const QString description() { return m_setting.desc; }

    //QSize sizeHint() const;

private:
    void init();

protected:
    void mouseDoubleClickEvent(QMouseEvent *);
    void contextMenuEvent(QContextMenuEvent* e);

protected slots:
    void onclick();
    void onConnected();
    void onReadData();
    void onTimeout();
    void onReconnAction();
    void onSocketError(QAbstractSocket::SocketError);

private:
    NodeDetail *m_detail;

    QLabel* m_address;
    QLabel* m_description;
    QLabel* m_status;

    QTcpSocket *m_socket;

    NodeSetting m_setting;

    QAction *m_reconnectAction;

    QTimer *m_timer;
};

#endif // DEVICEBUTTON_H
