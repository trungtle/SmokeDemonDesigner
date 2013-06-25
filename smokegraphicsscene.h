#ifndef SMOKEGRAPHICSSCENE_H
#define SMOKEGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsSimpleTextItem>

enum {
    SMOKE_LAYER_GRID,

    //
    // All game objects are added in layers >= SMOKE_LAYER_OBJECT
    //

    SMOKE_LAYER_OBJECT
};

typedef struct _SmokeGrid_t
{
    QList<QGraphicsLineItem*> lines;
    QList<QGraphicsSimpleTextItem*> coordinates;
} SmokeGrid_t;

class SmokeLayer : public QGraphicsItem
{
public:
    explicit SmokeLayer(
            QGraphicsItem *parent = 0
            ) :
        QGraphicsItem(parent)
    {

    }

    QRectF
    boundingRect()
    const
        {
            return QRectF();
        }

    void
    paint(
            QPainter *,
            const QStyleOptionGraphicsItem *,
            QWidget *)
        {
        }

};

/* ----------------------------------------------------------------------------
 *
 * ------------------------------------------------------------------------- */
class SmokeGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit SmokeGraphicsScene(
            qreal width,
            qreal height,
            QObject *parent = 0
            );

    ~SmokeGraphicsScene();

    //
    // Overriding addItem to include layers
    //

    void
    addItem(QGraphicsItem *item,
            int layerIndex = SMOKE_LAYER_OBJECT
            );

    void
    addLayer(
            SmokeLayer *layer
            );

    //
    // Accessors
    //

    void
    setGridOn(bool isOn);

private:

    SmokeGrid_t m_grid;
    QList<SmokeLayer*> m_layers;

    //
    // Helpers
    //

    void createGrid();

signals:
    
public slots:
    
};


#endif // SMOKEGRAPHICSSCENE_H
