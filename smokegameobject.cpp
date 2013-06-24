#include "smokegameobject.h"

//
// @tle_todo: pass in as parameter instead
//

const QString TEXTURE_FILENAME = ":/img/vision_ward.png";

SmokeGameObject::SmokeGameObject(
        qreal x,
        qreal y,
        qreal z,
        qreal angle,
        qreal scale) :
    QStandardItemModel(0, COLS)
{
    this->graphicsItem = new SmokeGraphicsItem(QPixmap(TEXTURE_FILENAME));
    this->graphicsItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);

    this->createTransformation(x, y, z, angle, scale);
}

SmokeGameObject::~SmokeGameObject()
{
    delete this->graphicsItem;
}

QGraphicsPixmapItem*
SmokeGameObject::getGraphicsItem(
        )
{
    return this->graphicsItem;
}

void
SmokeGameObject::createTransformation(
        qreal x,
        qreal y,
        qreal z,
        qreal angle,
        qreal scale)
{
    this->graphicsItem->setPos(QPointF(x, y));
    this->graphicsItem->setZValue(z);
    this->graphicsItem->setRotation(angle);
    this->graphicsItem->setScale(scale);

    QStandardItem* transformationRoot = new QStandardItem("Transformation");
    this->invisibleRootItem()->appendRow(transformationRoot);

    this->createLabelEditRow("x", QString("%1").arg(x), transformationRoot);
    this->createLabelEditRow("y", QString("%1").arg(y), transformationRoot);
    this->createLabelEditRow("z", QString("%1").arg(z), transformationRoot);
    this->createLabelEditRow("Angle", QString("%1").arg(angle), transformationRoot);
    this->createLabelEditRow("Scale", QString("%1").arg(scale), transformationRoot);

}

QStandardItem*
SmokeGameObject::createLabelItem(
        QString name
        )
{
    QStandardItem* label = new QStandardItem(name);
    label->setSelectable(false);
    label->setEditable(false);
    label->setBackground(QBrush(Qt::darkGray));
    return label;
}

void
SmokeGameObject::createLabelEditRow(
        QString label,
        QString value,
        QStandardItem* parent
        )
{
    QStandardItem* labelItem = this->createLabelItem(label);
    QStandardItem* editItem = new QStandardItem(value);

    QList<QStandardItem*> row;
    row << labelItem << editItem;
    parent->appendRow(row);
}

//QVariant SmokeGameObject::data(const QModelIndex &index, int role) const
//{
//    int row = index.row();
//    int col = index.column();

//    switch(role) {
//    case Qt::DisplayRole:
//        if (row == GAMEOBJ_TEXTURE) {

//            //
//            // Texture
//            //

//            return TEXTURE_FILENAME;
//        }

//        if (row == GAMEOBJ_TRANSFORMATION) {

//            //
//            // Transformation
//            //
//            QString returnString =
//                    QString("%1 %2 %3".arg(this->graphicsItem));
//        }
//    }
//}


