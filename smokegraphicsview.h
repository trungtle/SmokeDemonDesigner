#ifndef SMOKEGRAPHICSVIEW_H
#define SMOKEGRAPHICSVIEW_H

#include <QGraphicsView>

class SmokeGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit SmokeGraphicsView(QWidget *parent = 0);
    ~SmokeGraphicsView();
    
protected:
    void
    keyPressEvent(
            QKeyEvent* event
            );

    void
    keyReleaseEvent(
            QKeyEvent* event
            );

private:

signals:
    
public slots:
    
};

#endif // SMOKEGRAPHICSVIEW_H
