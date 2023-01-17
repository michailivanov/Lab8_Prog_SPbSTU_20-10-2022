#ifndef FIELDLINEEDIT_H
#define FIELDLINEEDIT_H

#include <QLineEdit>
#include "datavalidator.h"

class Field : public QLineEdit
{
    Q_OBJECT
    const fieldType _type;
    bool validate(const QString & s) const;
    void toRed();
    void toBlack();
public:
    static QString DelSpacesBeforeAndAfter(const QString & s);
    static QString DelDoubledSpaces(const QString & s);
    static QString DelAllSpaces(const QString & s);
    static QString DelAllNonNumbers(const QString & s);
    bool isValid() const;
    Field(const enum fieldType& t);
public slots:
    void whenTextEdited(const QString&);
};

#endif // FIELDLINEEDIT_H
