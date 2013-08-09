#include "smokedockwidget.h"

SmokeDockWidget::SmokeDockWidget(const QString& title,QWidget *parent) :
    QDockWidget(parent)
{
    setWindowTitle(title);
    m_titleWidget = new QLabel(title);
    setTitleBarWidget(m_titleWidget);

    m_tabWidget = new QTabWidget(this);
    setWidget(m_tabWidget);

    setFeatures(NoDockWidgetFeatures);

    connect(this,SIGNAL(dockLocationChanged(Qt::DockWidgetArea)),SLOT(DockAreaChanged(Qt::DockWidgetArea)));
    connect(this,SIGNAL(topLevelChanged(bool)),SLOT(FloatChanged(bool)));
}

SmokeDockWidget::~SmokeDockWidget()
{
    while(m_tabWidget->count() > 0)
    {
        QWidget* widget = m_tabWidget->currentWidget();
        delete widget;
        m_tabWidget->removeTab(0);
    }
    delete m_tabWidget;
    delete m_titleWidget;
}

void SmokeDockWidget::ToggleTitle()
{
    if(titleBarWidget() == m_titleWidget)
    {
        setTitleBarWidget(0);
        setFeatures(DockWidgetClosable|
                    DockWidgetMovable|
                    DockWidgetFloatable);
    }
    else
    {
        setTitleBarWidget(m_titleWidget);
        setFeatures(NoDockWidgetFeatures);
    }
}

void SmokeDockWidget::AddTab(const QString &name, QWidget *widget)
{
    m_tabWidget->addTab(widget,name);
}

void SmokeDockWidget::DockAreaChanged(Qt::DockWidgetArea area)
{
    switch(area)
    {
        case Qt::LeftDockWidgetArea:
            m_tabWidget->setTabPosition(QTabWidget::West);
            break;
        case Qt::RightDockWidgetArea:
            m_tabWidget->setTabPosition(QTabWidget::East);
            break;
        default:
            m_tabWidget->setTabPosition(QTabWidget::North);
    }
}

void SmokeDockWidget::FloatChanged(bool floating)
{
    if(floating)
        m_tabWidget->setTabPosition(QTabWidget::North);
}
