#include "name.h"



void Name::setData(int role, const QVariant &value)
{
    switch (role)
    {
    case Ur::Name:
        this->setText(value.toString());
        break;
    default:
        break;
    }
}

QVariant Name::data(int role) const
{
    switch (role)
    {
    case Ur::Name:
        this->text();
        break;
    default:
        break;
    }
}
