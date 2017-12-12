#ifndef DEVICENODE_H
#define DEVICENODE_H

#include <QObject>
#include <QListWidgetItem>

class DeviceNode : public QObject, public QListWidgetItem
{
    Q_OBJECT

public:
    DeviceNode(const QString& text, QListWidget* parent=0, bool status=true);
};

#endif // DEVICENODE_H
