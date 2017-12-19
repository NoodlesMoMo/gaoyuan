#include "mainpanal.h"
#include <QListView>
#include "devicenode.h"
#include <QSplitter>
#include <QScrollArea>
#include <QCloseEvent>
#include <QMessageBox>
#include <QSettings>
#include <QDebug>

const QString OrgName("gaoyuan.org");
const QString AppName("gy_monitor");

MainPanal::MainPanal()
{
    init();

    m_controller = new Controller;
    connect(m_controller, SIGNAL(resultRelay(QString)), this, SLOT(onWorkResult(QString)));
    m_controller->start();

    load();
}

void MainPanal::init()
{
    m_device_panel = new QWidget(this);

    QScrollArea *scroll_area = new QScrollArea;
    scroll_area->setWidget(m_device_panel);
    scroll_area->setBackgroundRole(QPalette::Dark);
    scroll_area->setAutoFillBackground(true);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scroll_area->setWidgetResizable(true);

    m_tab_detail = new QTabWidget;
    m_detail = new NodeDetail(m_tab_detail);
    m_tab_detail->addTab(m_detail, "detail");
    m_tab_detail->setMaximumWidth(500);
    m_gridLayout = new QGridLayout(m_device_panel);

    addWidget(scroll_area);
    addWidget(m_tab_detail);
}

MainPanal::~MainPanal()
{
    if(m_controller != NULL){
        m_controller->stop();
    }
}

void MainPanal::onWorkResult(const QString &result)
{
    Q_UNUSED(result);

    //m_detail->setText(result);
}

void MainPanal::onClose()
{
    if(m_controller != NULL){
        m_controller->stop();
    }
}

void MainPanal::addDeviceNode(NodeSetting setting)
{
    if(m_dev_nodes.contains(setting.id())){
        QMessageBox::critical(this, QString::fromUtf8("添加失败"),
                              QString::fromUtf8("与现有监控设备冲突"),
                              QMessageBox::Ok);
        return;
    }

    int index = m_dev_nodes.size();
    DeviceButton *dev = new DeviceButton(m_detail, setting);
    m_gridLayout->addWidget(dev, index/4, index%4, 1, 1);
    m_dev_nodes.insert(setting.id(), dev);

    save();
}

void MainPanal::delDeviceNode(const QString& id)
{
    if(m_dev_nodes.contains(id)){
        DeviceButton* dev = m_dev_nodes[id];
        dev->close();
        delete dev;
        m_dev_nodes.remove(id);
    }

    save();
}

void MainPanal::save()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, OrgName, AppName, this);
    settings.beginWriteArray("deviceNodes");
    QMap<QString, DeviceButton*>::iterator iter = m_dev_nodes.begin();
    int index = 0;
    for (; iter!=m_dev_nodes.end(); ++iter, index++) {
        settings.setArrayIndex(index);
        settings.setValue("ip", (*iter)->ip());
        settings.setValue("port", (*iter)->port());
        settings.setValue("desc", (*iter)->description());
    }
    settings.endArray();
}

void MainPanal::load()
{
    QSettings setting(QSettings::IniFormat, QSettings::UserScope, OrgName, AppName, this);
    int size=setting.beginReadArray("deviceNodes");

    for(int i=0; i<size; i++){
        setting.setArrayIndex(i);
        NodeSetting node_setting;
        node_setting.ip = setting.value("ip").toString();
        node_setting.port = setting.value("port").toString();
        node_setting.desc = setting.value("desc").toString();
        addDeviceNode(node_setting);
    }

    setting.endArray();
}

