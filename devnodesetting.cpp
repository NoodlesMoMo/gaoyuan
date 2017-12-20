#include "devnodesetting.h"
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

DevNodeSetting::DevNodeSetting(QWidget* parent)
    : QDialog(parent)
{
    QGridLayout *layout = new QGridLayout(this);
    QLabel *ip_lbl = new QLabel("IP");
    QLabel *port_lbl = new QLabel("Port");
    QLabel *desc_lbl = new QLabel("Description");

    ip_lbl->setAlignment(Qt::AlignCenter);
    port_lbl->setAlignment(Qt::AlignCenter);
    desc_lbl->setAlignment(Qt::AlignCenter);

    m_ip = new QLineEdit;
    m_port = new QLineEdit;
    m_description = new QLineEdit;

    m_port->setText("26");

    ip_lbl->setBuddy(m_ip);
    port_lbl->setBuddy(m_port);
    desc_lbl->setBuddy(m_description);

    layout->addWidget(ip_lbl, 0, 0, 1, 1);
    layout->addWidget(m_ip, 0, 1, 1, 3);
    layout->addWidget(port_lbl, 1, 0, 1, 1);
    layout->addWidget(m_port, 1, 1, 1, 3);
    layout->addWidget(desc_lbl, 2, 0, 1, 1);
    layout->addWidget(m_description, 2, 1, 1, 3);

    m_ok_btn = new QPushButton("OK");
    m_cancle_btn = new QPushButton("Cancle");

    layout->addWidget(m_ok_btn, 4, 2, 1, 1);
    layout->addWidget(m_cancle_btn, 4, 3, 1, 1);

    setWindowTitle("setting");

    connect(m_ok_btn, SIGNAL(clicked(bool)), this, SLOT(onOkClick()));
    connect(m_cancle_btn, SIGNAL(clicked(bool)), this, SLOT(onCancleClick()));
}

QSize DevNodeSetting::sizeHint() const{
    return QSize(420, 200);
}

void DevNodeSetting::onOkClick()
{
    m_setting.ip = m_ip->text();
    m_setting.port = m_port->text();
    m_setting.desc = m_description->text();

    emit settingConfirm(m_setting);

    close();
}

void DevNodeSetting::onCancleClick()
{
    close();
}

const NodeSetting& DevNodeSetting::getSetting() const
{
    return m_setting;
}

