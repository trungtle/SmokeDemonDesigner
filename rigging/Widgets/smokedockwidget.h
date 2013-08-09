#ifndef SMOKEDOCKWIDGET_H
#define SMOKEDOCKWIDGET_H

#include <QDockWidget>
#include <QLabel>
#include <QTabWidget>

class SmokeDockWidget : public QDockWidget
{
    Q_OBJECT
public:
    explicit SmokeDockWidget(const QString& title="",QWidget *parent = 0);
    ~SmokeDockWidget();

    void ToggleTitle();
    void AddTab(const QString & name,QWidget* widget=0);
signals:
    
public slots:
    void DockAreaChanged(Qt::DockWidgetArea area);
    void FloatChanged(bool floating);

private:
    QLabel* m_titleWidget;
    QTabWidget* m_tabWidget;
};

#endif // SMOKEDOCKWIDGET_H
