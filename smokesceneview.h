#ifndef SMOKESCENEVIEW_H
#define SMOKESCENEVIEW_H

#include <QGraphicsView>

class SmokeSceneView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit SmokeSceneView(QWidget *parent = 0);
    
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:

signals:
    
public slots:
    
};

#endif // SMOKESCENEVIEW_H
