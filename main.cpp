#include <QtGui>
#include "mainpanal.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QFile skin(":/res/skin.qss");
    skin.open(QFile::ReadOnly);
    if(skin.isOpen()){
        qApp->setStyleSheet(QLatin1String(skin.readAll()));
        skin.close();
    }

    QMainWindow win;

    MainPanal *centralWidget = new MainPanal;

    win.setCentralWidget(centralWidget);
    win.setWindowTitle(QString::fromUtf8("高源电气"));
    win.showMaximized();

    return app.exec();
}
