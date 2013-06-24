#ifndef SMOKEGRAPHICSSCENE_H
#define SMOKEGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsSimpleTextItem>

typedef struct _SmokeGrid_t
{
    QList<QGraphicsLineItem*> lines;
    QList<QGraphicsSimpleTextItem*> coordinates;
} SmokeGrid_t;


/* ----------------------------------------------------------------------------
 *
 * ------------------------------------------------------------------------- */
class SmokeGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit SmokeGraphicsScene(QObject *parent = 0);

    //
    // Accessors
    //

    void setGridOn(bool isOn);

private:

    SmokeGrid_t grid;

    //
    // Helpers
    //

    void createGrid();

signals:
    
public slots:
    
};


#endif // SMOKEGRAPHICSSCENE_H
