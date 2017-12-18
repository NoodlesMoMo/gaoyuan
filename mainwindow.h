#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QAction>
#include "devnodesetting.h"
#include "mainpanal.h"

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private:
    void createMenus();
    void createToolBar();

protected:
    void closeEvent(QCloseEvent* e);

protected slots:
    void onAddAction();
    void onDelAction();

private:
    QAction *m_addDevAction;
    QAction *m_delDevAction;

    DevNodeSetting* m_setting_dlg;
};

#endif // MAINWINDOW_H
