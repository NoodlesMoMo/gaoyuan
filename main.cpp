#include <QtGui>
#include "mainwindow.h"
#include "gylogger.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QFont font(QString::fromUtf8("微软雅黑"));
    qApp->setFont(font);

    QFile skin(":/res/skin.qss");
    skin.open(QFile::ReadOnly);
    if(skin.isOpen()){
        qApp->setStyleSheet(QLatin1String(skin.readAll()));
        skin.close();
    }

    openLog();
    MainWindow win;
    win.showMaximized();
    int ret = app.exec();
    closeLog();

    return ret;
}
