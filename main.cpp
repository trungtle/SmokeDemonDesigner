#include "SmokeMainWindow.h"
#include <QApplication>
#include <QStandardItemModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.showMaximized();
    
    return a.exec();
}
