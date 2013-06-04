#include <QKeyEvent>
#include "smokesceneview.h"

SmokeSceneView::SmokeSceneView(QWidget *parent) :
    QGraphicsView(parent)
{
    this->setDragMode(QGraphicsView::RubberBandDrag);
    this->centerOn(0,0);
}

void SmokeSceneView::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {
        this->setDragMode(QGraphicsView::ScrollHandDrag);
    }
    QGraphicsView::keyPressEvent(event);
}

void SmokeSceneView::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {
        this->setDragMode(QGraphicsView::RubberBandDrag);
    }
    QGraphicsView::keyPressEvent(event);
}
