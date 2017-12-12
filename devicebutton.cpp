#include "devicebutton.h"
#include <QTabWidget>
#include <QDebug>

DeviceButton::DeviceButton(NodeDetail* detail):
    m_detail(detail)
{
    setFixedSize(160, 100);
    connect(this, SIGNAL(clicked(bool)), this, SLOT(onclick()));
}

void DeviceButton::setStatus(DeviceStatus status)
{
    switch(status){
    case OK:
        setStyleSheet(ok_style_sheet);
        break;

    case FAULT:
        setStyleSheet(fault_style_sheet);
        break;

    case DISCONNECT:
        setStyleSheet(disconnect_style_sheet);
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
    m_detail->setText(this->text());
}
