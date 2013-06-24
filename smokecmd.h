#ifndef SMOKECMD_H
#define SMOKECMD_H

#include <QString>
#include <QStandardItem>
#include <QUndoCommand>
#include "smokegraphicsscene.h"

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
    AddCommand(SmokeGraphicsScene *graphicsScene,
               QUndoCommand *parent = 0);
    ~AddCommand();

    void undo();
    void redo();

private:
    QGraphicsScene *myGraphicsScene;
    QPointF initialPosition;
};

#endif // SMOKECMD_H
