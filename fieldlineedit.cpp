#include "fieldlineedit.h"

Field::Field(const enum fieldType& t) : _type(t)
{
     connect(this, SIGNAL(textEdited(const QString&)), this, SLOT(whenTextEdited(const QString&)));
}

void Field::toRed()
{
    QPalette p;
    p.setColor(QPalette::Text, Qt::red);
    this->setPalette(p);
}

void Field::toBlack()
{
    QPalette p;
    p.setColor(QPalette::Text, Qt::black);
    this->setPalette(p);
}

bool Field::isValid() const
{
    return validate(this->text());
}

void Field::whenTextEdited(const QString& s)
{
    //save cursor position
    int pos = cursorPosition();

    //set text without spaces
    this->setText(DelDoubledSpaces(s));

    //change colour if text is invalid
    if(validate(this->text()))
        toBlack();
    else
        toRed();

    //set cursor position
    this->setCursorPosition(pos);
}

QString Field::DelSpacesBeforeAndAfter(const QString & s)
{
    //удалить незнач. пробелы в начале и в конце
    QString res(s);
    res.replace(QRegularExpression("(^[ ]{1,})|([ ]{1,}$)"), "");
    return res;
}
QString Field::DelDoubledSpaces(const QString & s)
{
    QString res(s);
    // заменить все двойные+ пробелы на одинарные
    while(QRegularExpressionMatch(\
              QRegularExpression("  ").match(res)).hasMatch())
    {
        res.replace(QRegularExpression("  "), " ");
    }
    return res;
}

QString Field::DelAllSpaces(const QString & s)
{
    QString res(s);
    // Удалить все пробелы
    res.replace(QRegularExpression(" "), "");
    return res;
}

QString Field::DelAllNonNumbers(const QString &s)
{
    QString res(s);
    // Удалить все не цифры
    res.replace(QRegularExpression("[^0-9]"), "");
    return res;
}

bool Field::validate(const QString &s) const
{
    DataValidator d;
    return d(_type, s);
}



