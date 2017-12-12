#ifndef MAINPANAL_H
#define MAINPANAL_H

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QTabWidget>
#include <QSplitter>

#include "devicebutton.h"
#include "nodedetail.h"

class MainPanal : public QSplitter
{
    Q_OBJECT

public:
    MainPanal();

    void init();

private:
    QWidget *m_device_panel;
    QTabWidget *m_tab_detail;
    QSplitter *m_splitter;
    NodeDetail *m_detail;
};

#endif // MAINPANAL_H
