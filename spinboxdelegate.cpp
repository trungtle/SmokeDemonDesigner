#include <QSpinBox>
#include "spinboxdelegate.h"

SpinBoxDelegate::SpinBoxDelegate(QObject *parent) :
    QItemDelegate(parent)
{
}

QWidget*
SpinBoxDelegate::createEditor(
        QWidget *parent,
        const QStyleOptionViewItem &option,
        const QModelIndex &index) const
{
    QSpinBox* editor = new QSpinBox();
    return editor;
}

void
SpinBoxDelegate::setEditorData(
        QWidget *editor,
        const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::EditRole).toInt();

    QSpinBox* spinBox = static_cast<QSpinBox*>(editor);
    spinBox->setValue(value);
}

void
SpinBoxDelegate::setModelData(
        QWidget *editor,
        QAbstractItemModel *model,
        const QModelIndex &index) const
{
    QSpinBox* spinBox = static_cast<QSpinBox*>(editor);
    spinBox->interpretText();
    int value = spinBox->value();
    model->setData(index, value, Qt::EditRole);

}

void
SpinBoxDelegate::updateEditorGeometry(
        QWidget *editor,
        const QStyleOptionViewItem &option,
        const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
