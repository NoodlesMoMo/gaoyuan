#include <QtGui>
#include "mainwindow.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

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
