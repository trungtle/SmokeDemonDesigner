#ifndef SMOKECMD_H
#define SMOKECMD_H

#include <QString>
#include <QStandardItem>

class SmokeCmd : public QStandardItem
{

public:
    explicit SmokeCmd(const QStringList &commandSyntax, const QString &helpInfo);
    QStringList alias;
    QString helpInfo;
};

#endif // SMOKECMD_H
