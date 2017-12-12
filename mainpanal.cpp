#include "mainpanal.h"
#include <QListView>
#include "devicenode.h"
#include <QSplitter>
#include <QScrollArea>

MainPanal::MainPanal()
{
    init();
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
    scroll_area->setMaximumWidth(800);

    m_tab_detail = new QTabWidget;
    m_detail = new NodeDetail(m_tab_detail);
    m_tab_detail->addTab(m_detail, "detail");

    QGridLayout *gridLayout = new QGridLayout(m_device_panel);
//    gridLayout->setSizeConstraint(QLayout::SetMaximumSize);

    for(int i=0; i<60; i++){
        DeviceButton *dev = new DeviceButton(m_detail);
        int row = i / 4;
        int col = i % 4;
        dev->setText(QString("device node %1").arg(i));
        dev->setStatus(DeviceButton::DeviceStatus(i%2));
        gridLayout->addWidget(dev, row, col, 1, 1);
    }

    addWidget(scroll_area);
    addWidget(m_tab_detail);

//    setStretchFactor(0, 5);
//    setStretchFactor(1, 5);
}

