#include <QKeyEvent>
#include "smokegraphicsview.h"

SmokeGraphicsView::SmokeGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
    this->setDragMode(QGraphicsView::RubberBandDrag);
    this->centerOn(0,0);
}

SmokeGraphicsView::~SmokeGraphicsView()
{
}

void SmokeGraphicsView::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {
        this->setDragMode(QGraphicsView::ScrollHandDrag);
    }
    QGraphicsView::keyPressEvent(event);
}

void SmokeGraphicsView::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {
        this->setDragMode(QGraphicsView::RubberBandDrag);
    }
    QGraphicsView::keyPressEvent(event);
}
