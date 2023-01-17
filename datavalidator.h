#ifndef DATAVALIDATOR_H
#define DATAVALIDATOR_H
#include <QRegularExpression>
#include "Constants.h"

class DataValidator
{
public:
    bool operator()(const fieldType& type, const QString &s);
};

#endif // DATAVALIDATOR_H
