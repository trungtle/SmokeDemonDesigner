#include "SmokeCmd.h"

SmokeCmd::SmokeCmd(const QStringList &alias, const QString &helpInfo) :
    QStandardItem()
{
    this->alias = alias;
    this->helpInfo = helpInfo;
}

SmokeCmd::~SmokeCmd()
{
}
