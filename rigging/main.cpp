#include "smokemainwindow.h"
#include <QApplication>

int main(int argc,char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    QPalette p = a.palette();

    p.setColor(QPalette::Window, QColor(53,53,53));
    p.setColor(QPalette::Button, QColor(53,53,53));
    p.setColor(QPalette::Highlight, QColor(142,45,197));
    p.setColor(QPalette::ButtonText, QColor(255,255,255));
    p.setColor(QPalette::WindowText, QColor(255,255,255));
    p.setColor(QPalette::Text, QColor(255,255,255));
    p.setColor(QPalette::Base,QColor(53,53,53));
    a.setPalette(p);
    SmokeMainWindow w;
    w.show();

    return a.exec();
}
