#ifndef NAME_H
#define NAME_H

#include <QTableWidgetItem>
#include <QException>
enum Ur
{
    Name = 256,
    Email,
    Birthday,
    Address,
    Phone
};
class Name : public QTableWidgetItem
{
public:
    Name();
    virtual void setData(int role, const QVariant &value);

    virtual QVariant data(int role) const;
};

#endif // NAME_H
