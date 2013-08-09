#include <QKeyEvent>
#include "SmokeGraphicsView.h"

SmokeGraphicsView::SmokeGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
    this->setDragMode(QGraphicsView::RubberBandDrag);
    this->centerOn(0,0);
}

SmokeGraphicsView::~SmokeGraphicsView()
{
}

void
SmokeGraphicsView::keyPressEvent(
        QKeyEvent *event
        )
{
    if (event->key() == Qt::Key_Space) {

        //
        // Panning on key down
        //

        this->setDragMode(QGraphicsView::ScrollHandDrag);
    }
    QGraphicsView::keyPressEvent(event);
}

void
SmokeGraphicsView::keyReleaseEvent(
        QKeyEvent *event
        )
{
    if (event->key() == Qt::Key_Space) {

        //
        // Panning off
        //

        this->setDragMode(QGraphicsView::RubberBandDrag);
    }
    QGraphicsView::keyReleaseEvent(event);
}

void
SmokeGraphicsView::wheelEvent(
        QWheelEvent* event
        ) {

    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    // Scale the view / do the zoom
    double scaleFactor = 1.15;

    QPoint delta = event->angleDelta();
    if(delta.y() > 0) {
        // Zoom in
        scale(scaleFactor, scaleFactor);
    } else {
        // Zooming out
        scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }

    // Don't call superclass handler here
    // as wheel is normally used for moving scrollbars
}
