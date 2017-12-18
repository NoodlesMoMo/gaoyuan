#ifndef MAINPANAL_H
#define MAINPANAL_H

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QTabWidget>
#include <QSplitter>
#include <QMap>

#include "devicebutton.h"
#include "nodedetail.h"
#include "work_thread.h"
#include "devnodesetting.h"

class MainPanal : public QSplitter
{
    Q_OBJECT

public:
    MainPanal();

    ~MainPanal();

    void init();

    void onClose();

    void addDeviceNode();
    void delDeviceNode(const QString &id);

    void save();
    void load();

protected slots:
    void onWorkResult(const QString& result);
    void addDeviceNode(NodeSetting setting);

private:
    QWidget *m_device_panel;
    QTabWidget *m_tab_detail;
    QSplitter *m_splitter;
    NodeDetail *m_detail;

    Controller *m_controller;

    QGridLayout *m_gridLayout;

    QMap<QString, DeviceButton*> m_dev_nodes;
};

#endif // MAINPANAL_H
