#ifndef CUSTOMTABLEDELEGATE_H
#define CUSTOMTABLEDELEGATE_H

#include <QStyledItemDelegate>

class CustomTableDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    CustomTableDelegate();
    virtual void setModelData  (QWidget *, QAbstractItemModel *, const QModelIndex &) const;
};

#endif // CUSTOMTABLEDELEGATE_H
