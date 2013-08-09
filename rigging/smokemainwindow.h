#ifndef SMOKEMAINWINDOW_H
#define SMOKEMAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include "smokedockwidget.h"

namespace Ui {
class SmokeMainWindow;
}

class SmokeMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit SmokeMainWindow(QWidget *parent = 0);
    ~SmokeMainWindow();

public slots:
    void toggle();

private:
    Ui::SmokeMainWindow *ui;
    SmokeDockWidget* m_browseWidget;
    SmokeDockWidget* m_statusWidget;
    SmokeDockWidget* m_attributeWidget;
    QShortcut* shortcut;
};

#endif // SMOKEMAINWINDOW_H
