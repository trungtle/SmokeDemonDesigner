#ifndef SMOKE_MAINWINDOW_H
#define SMOKE_MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemModel>
#include <QStandardItemModel>
#include <QGraphicsRectItem>
#include <QGraphicsView>

//
// Custom Smoke classes
//

#include "SmokegraphicsView.h"
#include "SmokeCmd.h"
#include "SmokeGameObject.h"
#include "SmokeGraphicsScene.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    SmokeGameObject* currentGameObject;
    QList<SmokeGameObject*> gameObjectList;
    SmokeGraphicsScene* scene;
    QStandardItemModel* cmdModel;
    QStringList cmdStringList;

    void
    createActions(
            );

    void
    createGrid(
            );

    void
    createCmdModel(
            );

    void
    createCmd(
            SmokeCmd &cmd
            );

    void
    createScene(
            );

    //
    // Prepare initial state for widgets
    //

    void
    prepareToolbar(
            );

    void
    prepareResourceView(
            );

    void
    prepareCmdView(
            );

    void
    prepareObjectInspector();

    void
    prepareSceneView(SmokeGraphicsView *view);

    void
    prepareSceneTab();

    void
    prepareCmdLine();

    // Helpers
    bool
    parseCoord(
            QString& string,
            double &x,
            double &y
            );

private slots:

    void
    displayHelp(
            QModelIndex index
            );

    void
    activateCmd(
            );

    void
    addSceneTab();

    void closeCurrentSceneTab(
            );

    void
    addGameObject(
            QString name,
            qreal x,
            qreal y
            );

    void
    centerOn(
            qreal x,
            qreal y
            );

    void
    executeCmd(
            );

    void
    updateInspectorSelectionChanged(
            );
};

#endif // SMOKE_MAINWINDOW_H
