#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>

MainWindow::MainWindow(): m_setting_dlg(NULL)
{
    MainPanal* panel = new MainPanal;
    setCentralWidget(panel);
    createToolBar();

    setWindowTitle(QString::fromUtf8("高源电气"));
    setWindowIcon(QIcon(":/res/logo.png"));
}

void MainWindow::createToolBar()
{
    m_addDevAction = new QAction(QIcon(":/res/add.png"), QString::fromUtf8("添加"), this);
    m_delDevAction = new QAction(QIcon(":/res/del.png"), QString::fromUtf8("删除"), this);

    connect(m_addDevAction, SIGNAL(triggered(bool)), this, SLOT(onAddAction()));
    connect(m_delDevAction, SIGNAL(triggered(bool)), this, SLOT(onDelAction()));

    QToolBar *devBar = addToolBar(QString("设备"));
    devBar->addAction(m_addDevAction);
    devBar->addAction(m_delDevAction);
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e)

    MainPanal *panel = dynamic_cast<MainPanal*>(centralWidget());
    if(panel != NULL){
        panel->onClose();
    }
}

void MainWindow::onAddAction()
{
    if(m_setting_dlg == NULL){
        m_setting_dlg = new DevNodeSetting(this);
        connect(m_setting_dlg,
                SIGNAL(settingConfirm(NodeSetting)),
                dynamic_cast<MainPanal*>(centralWidget()),
                SLOT(addDeviceNode(NodeSetting)));
    }

    m_setting_dlg->exec();
}

void MainWindow::onDelAction()
{
    bool ok;
    QString id = QInputDialog::getText(this, QString::fromUtf8("删除节点"),
                                       QString::fromUtf8("设备节点ID"),
                                       QLineEdit::Normal, "", &ok);
    MainPanal *panel = dynamic_cast<MainPanal*>(centralWidget());
    if(panel != NULL){
        if(ok && !id.isEmpty())
            panel->delDeviceNode(id);
    }
}

