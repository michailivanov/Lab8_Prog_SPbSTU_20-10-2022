#include "datavalidator.h"

bool DataValidator::operator()(const fieldType& type, const QString &s)
{
    QRegularExpression re(REG.at(type)); //TOFIX
    QRegularExpressionMatch match = re.match(s);
    return match.hasMatch();
}
