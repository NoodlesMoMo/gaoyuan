#include <QtGui>
#include "mainwindow.h"

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

    MainWindow win;
    win.showMaximized();
//    win.show();

    return app.exec();
}
