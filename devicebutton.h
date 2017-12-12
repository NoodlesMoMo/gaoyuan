#ifndef DEVICEBUTTON_H
#define DEVICEBUTTON_H

#include <QPushButton>
#include <QString>
#include <QWidget>

#include "nodedetail.h"

const QString ok_style_sheet = QString("background-color: green;");
const QString fault_style_sheet = QString("background-color: red");
const QString disconnect_style_sheet = QString("background-color: yellow");

class DeviceButton : public QPushButton
{
    Q_OBJECT

public:
    enum DeviceStatus{OK, FAULT, DISCONNECT};

public:
    DeviceButton(NodeDetail* detail);

    void setStatus(DeviceStatus status);

    //QSize sizeHint() const;

protected slots:
    void onclick();

private:
    NodeDetail *m_detail;
};

#endif // DEVICEBUTTON_H
