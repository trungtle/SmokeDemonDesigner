#include <QShortcut>
#include <QPushButton>
#include <QFileSystemModel>
#include <QCompleter>
#include <QGraphicsView>
#include <QTime>
#include <QDebug>

#include "SmokeMainwindow.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFont(QFont("Museo Slab 500", 10));

    //
    // Create objects
    //

    this->createActions();
    this->createCmdModel();

    //
    // Setup ui initial state
    //

    this->prepareToolbar();
    this->prepareResourceView();
    this->prepareCmdView();
    this->prepareObjectInspector();
    this->prepareCmdLine();
    this->prepareSceneTab();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void
MainWindow::createActions(
        )
{
    QShortcut* ctrl_w = new QShortcut(QKeySequence("Ctrl+W"), this);
    QObject::connect(ctrl_w, SIGNAL(activated()), this, SLOT(closeCurrentSceneTab()));

    QShortcut* ctrl_t = new QShortcut(QKeySequence("Ctrl+T"), this);
    QObject::connect(ctrl_t, SIGNAL(activated()), this, SLOT(addSceneTab()));

    QShortcut* ctrl_e = new QShortcut(QKeySequence("Ctrl+E"), this);
    QObject::connect(ctrl_e, SIGNAL(activated()), this, SLOT(activateCmd()));
}

void
MainWindow::createCmdModel(
        )
{
    this->cmdModel = new QStandardItemModel(0, 2, this);
    this->cmdModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Commands"));

    //
    // @tle_todo: Move these help text out into resource files.
    //

    //
    // Create add cmd
    //

    QStringList aliasAdd;
    aliasAdd << "add" << "a";
    QString helpAdd = "\nDescription:\n" \
            "    Add a game object at specified location.\n" \
            "\nUsage:\n" \
            "    add x y [name]\n" \
            "\nExample:\n" \
            "    add 100 100 Player\n"
            "    a   231 12";
    SmokeCmd cmdAdd(aliasAdd, helpAdd);
    this->createCmd(cmdAdd);

    //
    // Create goto cmd
    //

    QStringList aliasGoto;
    aliasGoto << "goto" << ":";
    QString helpGoto = "\nDescription:\n" \
            "    Go to specified location.\n" \
            "\nUsage:\n" \
            "    :x y\n" \
            "\nExample:\n" \
            "    :120 50";
    SmokeCmd cmdGoto(aliasGoto, helpGoto);
    this->createCmd(cmdGoto);

    //
    // Create grid command
    //

    QStringList aliasGrid;
    aliasGrid << "grid";
    QString helpGrid = "\nDescription:\n" \
            "    Toggle grid on/off.\n" \
            "\nUsage:\n" \
            "    grid [on|off]\n" \
            "\nExample:\n" \
            "    grid off\n";
    SmokeCmd cmdGrid(aliasGrid, helpGrid);
    this->createCmd(cmdGrid);

    this->cmdModel->sort(0);
}

void
MainWindow::createCmd(
        SmokeCmd &cmd
        )
{
    this->cmdModel->insertRow(0);

    //
    // Use the 1st alias in list as default command name
    //

    this->cmdModel->setData(this->cmdModel->index(0, 0), cmd.alias.at(0));

    //
    // Add help info
    //

    this->cmdModel->setData(this->cmdModel->index(0, 1), cmd.helpInfo);
}

void
MainWindow::createScene(
        )
{
    //
    // Set size
    //

    const int SCENE_SIZE = 10000;

    this->scene = new SmokeGraphicsScene(SCENE_SIZE, SCENE_SIZE, this);
    QObject::connect(
                this->scene,
                SIGNAL(selectionChanged()),
                this,
                SLOT(updateInspectorSelectionChanged()));
}

/* -----------------------------------------------------------------------------
 * Function: prepareObject
 *
 * Params:
 *          None.
 *
 * Return:
 *
 *          None.
 * -------------------------------------------------------------------------- */
void
MainWindow::prepareObjectInspector(
        )
{
//    this->gameObjectModel = new QStandardItemModel(0, 1, this);

//    QList<QStandardItem*> preparedRow;
//    preparedRow << new QStandardItem("test1");
//    QStandardItem* item = this->gameObjectModel->invisibleRootItem();
//    item->appendRow(preparedRow);

//    QList<QStandardItem*> secondRow;
//    secondRow << new QStandardItem("test2");
//    preparedRow.first()->appendRow(secondRow);

//    ui->object_inspector->setModel(this->gameObjectModel);
//    ui->object_inspector->expandAll();

    ui->object_inspector->header()->setStyleSheet("color: black;");
//    ui->object_inspector->setItemDelegate(new SpinBoxDelegate(ui->object_inspector));
}

void
MainWindow::prepareSceneView(
        SmokeGraphicsView* view
        )
{
    view->setScene(this->scene);
}

void
MainWindow::prepareSceneTab(
        )
{
    this->createScene();

    this->prepareSceneView(ui->graphics_view);

    QObject::connect(ui->scene_tabs, SIGNAL(tabCloseRequested(int)), this, SLOT(closeCurrentSceneTab()));
}

void
MainWindow::prepareCmdLine(
        )
{
    QCompleter* cmdCompleter = new QCompleter(this->cmdStringList, this);

    ui->cmd->setCompleter(cmdCompleter);

    QObject::connect(ui->cmd, SIGNAL(returnPressed()), this, SLOT(executeCmd()));
}

void
MainWindow::prepareResourceView(
        )
{
    // Remove focus border
    ui->resource_view->setAttribute(Qt::WA_MacShowFocusRect, false);

    QFileSystemModel* resource_model = new QFileSystemModel(this);
    resource_model->setRootPath(QDir::currentPath());

    //
    // Set model
    //

    ui->resource_view->setModel(resource_model);
    ui->resource_view->setRootIndex(resource_model->index(QDir::currentPath()));

    //
    // Beautify it!
    //

    ui->resource_view->header()->setStyleSheet("color: black;");
    ui->resource_view->setColumnWidth(0, 180);
    ui->resource_view->setColumnWidth(1, 80);
    ui->resource_view->setColumnWidth(2, 80);
    ui->resource_view->setColumnWidth(3, 80);
}

void
MainWindow::prepareCmdView(
        )
{
    ui->cmd_view->setModel(this->cmdModel);

    QObject::connect(
                ui->cmd_view->selectionModel(),
                SIGNAL(currentChanged(QModelIndex,QModelIndex)),
                this,
                SLOT(displayHelp(QModelIndex)));
}

void
MainWindow::prepareToolbar(
        )
{
    //
    // New object
    //

    QPixmap add_pixmap(":/icons/Add16.png");
    QIcon add_buttonIcon(add_pixmap);

    QAction* add_action = ui->toolBar->addAction(add_buttonIcon, "Add new object");

    //
    // Help
    //

    QPixmap help_pixmap(":/icons/Faq16.png");
    QIcon help_buttonIcon(help_pixmap);

    QAction* help_action = ui->toolBar->addAction(help_buttonIcon, "Help");
    QObject::connect(help_action, SIGNAL(triggered()), this, SLOT(addSceneTab()));
}

/* -----------------------------------------------------------------------------
 * HELPERS
 *--------------------------------------------------------------------------- */
bool
MainWindow::parseCoord(
        QString &string,
        double &x,
        double &y
        )
{
    QStringList xyList = string.split(' ', QString::SkipEmptyParts, Qt::CaseInsensitive);

    if (xyList.count() == 2) {
        bool ok = false;
        x = xyList.at(0).toDouble(&ok);
        if (!ok) {
            return false;
        }

        y = xyList.at(1).toDouble(&ok);
        if (!ok) {
            return false;
        }

        return true;
    }

    return false;
}

void
MainWindow::displayHelp(
        QModelIndex index
        )
{
    //
    // Help index is of the same row of cmd, but column 1
    //

    ui->cmd_help->setText(
                this->cmdModel->data(
                    this->cmdModel->index(index.row(), 1)).toString());
}


/* -----------------------------------------------------------------------------
 * SLOTS
 *--------------------------------------------------------------------------- */
void
MainWindow::activateCmd(
        )
{
    ui->cmd->setFocus();
    ui->cmd->selectAll();
}

void
MainWindow::addSceneTab(
        )
{
    //
    // Create view to append to new tab
    //

    SmokeGraphicsView* view = new SmokeGraphicsView(this);
    this->prepareSceneView(view);

    int index = ui->scene_tabs->addTab(view, QString("New tab"));
    ui->scene_tabs->setCurrentIndex(index);
}

void
MainWindow::closeCurrentSceneTab(
        )
{
    //
    // If it's not the last tab, then close it
    //

    unsigned int currentIndex = ui->scene_tabs->currentIndex();
    ui->scene_tabs->removeTab(currentIndex);
}

void
MainWindow::addGameObject(
        QString name,
        qreal x,
        qreal y
        )
{
    this->currentGameObject = new SmokeGameObject(name, x, y);

    //
    // Add to our list of objects
    //

    gameObjectList << currentGameObject;
    scene->addItem(currentGameObject->getGraphicsItem());

    ui->object_inspector->setModel(currentGameObject);
    ui->object_inspector->resizeColumnToContents(0);
    ui->object_inspector->expandAll();

    //
    // Route output
    //

    ui->cmd_textoutput->append(
                QString("[%3] Added object at %1 %2.").arg(x).arg(y).arg(QTime::currentTime().toString()));

}

void
MainWindow::centerOn(
        qreal x,
        qreal y
        )
{
    //
    // @tle_todo: Current Widget doesn't work, investigate. Seems
    // like we can only select the 1st tab created.
    //

    SmokeGraphicsView* view =
            ui->scene_tabs->currentWidget()->findChild<SmokeGraphicsView*>();
    if (view)
    {
        view->centerOn(x,y);
        ui->cmd_textoutput->append(
                    QString("Center on %1 %2.").arg(x).arg(y)) ;
    }
}

void
MainWindow::executeCmd(
        )
{
    QString command = ui->cmd->text();
    if(command.startsWith("add", Qt::CaseInsensitive) ||
            command.startsWith("a", Qt::CaseInsensitive))
    {
        //
        // Parse the coordinate
        //

        QString xy = command.section(' ', 1, 2, QString::SectionSkipEmpty);
        double x, y;
        if (this->parseCoord(xy, x, y)) {

            QString name = command.section(' ', 3, 3);
            this->addGameObject(name, x, y);
        }

    }
    else if(command.startsWith(":", Qt::CaseInsensitive))
    {
        //
        // Parse the coordinate
        //
        QString xy = command.section(':', 1);

        double x, y;
        if(this->parseCoord(xy, x, y))
        {
            this->centerOn(x,y);
        }

    }
    else if(command.startsWith("grid", Qt::CaseInsensitive))
    {
        QString isOn = command.section(' ', 1);
        if (isOn.compare("on", Qt::CaseInsensitive) == 0) {
            scene->setGridOn(true);
        } else if (isOn.compare("off", Qt::CaseInsensitive) == 0) {
            scene->setGridOn(false);
        }
    }
}

void
MainWindow::updateInspectorSelectionChanged(
        )
{
    if (scene->selectedItems().count() == 1) {
        ui->object_inspector->setModel(static_cast<SmokeGraphicsItem*>(scene->selectedItems().at(0))->gameObject());
        ui->object_inspector->resizeColumnToContents(0);
        ui->object_inspector->expandAll();
    } else {
        ui->object_inspector->setModel(NULL);
    }
}
