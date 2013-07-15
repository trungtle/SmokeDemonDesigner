#include "SmokeMainWindow.h"
#include <QApplication>
#include <QStandardItemModel>
#include <QStyleFactory>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QPalette p;
    p = qApp->palette();
    p.setColor(QPalette::Window, QColor(53,53,53));
    p.setColor(QPalette::Button, QColor(53,53,53));
    p.setColor(QPalette::Highlight, QColor(142,45,197));
    p.setColor(QPalette::ButtonText, QColor(255,255,255));
    p.setColor(QPalette::WindowText, QColor(255, 255, 255));
    qApp->setPalette(p);

    QFontDatabase fontDatabase;
    fontDatabase.addApplicationFont(":/fonts/Museo Slab.otf");

    MainWindow w;
    w.showMaximized();
    
    return a.exec();
}
