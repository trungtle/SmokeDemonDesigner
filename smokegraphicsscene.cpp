#include <QDebug>
#include <QFontDatabase>
#include "SmokeGraphicsScene.h"

SmokeGraphicsScene::SmokeGraphicsScene(
        qreal width,
        qreal height,
        QObject *parent) :
    QGraphicsScene(parent)
{
    setSceneRect(
                QRectF(
                    -(width / 2),
                    -(height / 2),
                    width,
                    height)
                );

    //
    // Initial state
    //

    // SMOKE_LAYER_GRID
    addLayer(new SmokeLayer());
    // SMOKE_LAYER_OBJECT starts at this layer
    addLayer(new SmokeLayer());

    createGrid();
    setGridOn(false);

}

SmokeGraphicsScene::~SmokeGraphicsScene()
{
    m_layers.clear();
}

void
SmokeGraphicsScene::addItem(
        QGraphicsItem *item,
        int layerIndex
        )
{
    //
    // return if the layer index is out of range
    //

    if (layerIndex >= m_layers.count()) {
        return;
    }

    //
    // Deselect all other items
    //

    foreach(QGraphicsItem* graphicsItem, selectedItems()) {
        if (graphicsItem != item) {
            graphicsItem->setSelected(false);
        } else {
            graphicsItem->setSelected(true);
        }
    }

    QGraphicsScene::addItem(item);

    // @tle_todo: assign layer's parent (this doesn't seem like make hiding works)
    item->setParentItem(m_layers.at(layerIndex));

}

void
SmokeGraphicsScene::addLayer(
        SmokeLayer *layer
        )
{
    //
    // Add layer to custom list
    //

    m_layers << layer;

    //
    // Add layer to QGraphics scene
    //

    QGraphicsScene::addItem(layer);
}

void
SmokeGraphicsScene::setGridOn(
        bool isOn
        )
{
    if (isOn) {

        //
        // Turn on grid
        //

        for (int i = 0; i < m_grid.lines.count(); i++) {
            m_grid.lines.at(i)->show();
        }

        for (int i = 0; i < m_grid.coordinates.count(); i++) {
            m_grid.coordinates.at(i)->show();
        }

    } else {

        //
        // Hide grid
        //

        for (int i = 0; i < m_grid.lines.count(); i++) {
            m_grid.lines.at(i)->hide();
        }

        for (int i = 0; i < m_grid.coordinates.count(); i++) {
            m_grid.coordinates.at(i)->hide();
        }
    }
}

void
SmokeGraphicsScene::createGrid()
{
    int left = sceneRect().left();
    int right = sceneRect().right();
    int top = sceneRect().top();
    int bottom = sceneRect().bottom();

    const QColor darkGray(247, 247, 247, 20);
    for (int x = left; x < right; x+= 100)
    {
        QGraphicsLineItem *line = new QGraphicsLineItem(x, top, x, bottom);
        line->setPen(QPen(darkGray));

        m_grid.lines << line;
        addItem(line);
    }

    for (int y = top; y < bottom; y+= 100)
    {
        QGraphicsLineItem *line = new QGraphicsLineItem(left, y, right, y);
        line->setPen(QPen(darkGray));

        m_grid.lines << line;
        addItem(line);
    }

    //
    // Display some coord values
    //

    QFont font("Museo Slab 500", 10);
    for (int x = left; x < right; x+= 100) {
        for (int y = top; y < bottom; y+= 100) {

            QGraphicsSimpleTextItem* coordLabel =
                    new QGraphicsSimpleTextItem(QString("%1,%2").arg(x).arg(y));
            coordLabel->setBrush(darkGray);
            coordLabel->setFont(font);
            coordLabel->setPos(x, y);

            m_grid.coordinates << coordLabel;
            addItem(coordLabel);
        }
    }
}


