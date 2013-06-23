#ifndef SMOKECMD_H
#define SMOKECMD_H

#include <QString>
#include <QStandardItem>

class SmokeCmd : public QStandardItem
{

public:
    explicit SmokeCmd(const QStringList &commandSyntax, const QString &helpInfo);
    ~SmokeCmd();

    QStringList alias;
    QString helpInfo;
};

class AddCommand : public QUndoCommand
{
public:
    AddCommand(DiagramItem::DiagramType addType, QGraphicsScene *graphicsScene,
               QUndoCommand *parent = 0);
    ~AddCommand();

    void undo();
    void redo();

private:
    DiagramItem *myDiagramItem;
    QGraphicsScene *myGraphicsScene;
    QPointF initialPosition;
};

#endif // SMOKECMD_H
