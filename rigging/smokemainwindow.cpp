#include "smokemainwindow.h"
#include "ui_smokemainwindow.h"

SmokeMainWindow::SmokeMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SmokeMainWindow)
{
    ui->setupUi(this);

    resize(800,600);

    m_browseWidget = new SmokeDockWidget("Browse",this);
    m_browseWidget->AddTab("Resources",new QWidget());
    m_browseWidget->AddTab("Commands",new QWidget());
    m_browseWidget->AddTab("Template Database",new QWidget());

    m_statusWidget = new SmokeDockWidget("Status",this);
    m_statusWidget->AddTab("Console Output",new QWidget());

    m_attributeWidget = new SmokeDockWidget("Attribute",this);
    m_attributeWidget->AddTab("Object Inspector",new QWidget());
    m_attributeWidget->AddTab("Layer Inspector",new QWidget());


    shortcut = new QShortcut(QKeySequence("Ctrl+T"),this);
    this->connect(shortcut,SIGNAL(activated()),SLOT(toggle()));

    addDockWidget(Qt::LeftDockWidgetArea,m_browseWidget);
    addDockWidget(Qt::BottomDockWidgetArea,m_statusWidget);
    addDockWidget(Qt::RightDockWidgetArea,m_attributeWidget);
}

SmokeMainWindow::~SmokeMainWindow()
{
    delete m_attributeWidget;
    delete m_statusWidget;
    delete m_browseWidget;
    delete shortcut;
    delete ui;
}

void SmokeMainWindow::toggle()
{
    m_browseWidget->ToggleTitle();
    m_statusWidget->ToggleTitle();
    m_attributeWidget->ToggleTitle();
}
