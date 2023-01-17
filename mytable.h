#ifndef MYTABLE_H
#define MYTABLE_H

#include <QObject>
#include <QTableWidget>
#include <QRegularExpression>
#include <exception>



class MyTable : public QTableWidget
{
    Q_OBJECT
    static void DelSpacesFromStr(QString & s);
    bool changebleSortOrder;
public:
    MyTable();
    void addDataRow(const QStringList&);
public slots:
//    void toRed(const int&, const int&);//TODEL
//    void toGreen(const int&, const int&);//TODEL
//    void toGray(const int&, const int&);//TODEL
    void SortBySelectedColumn();

//    void addData(const int& i, const int& j, const QString& sl);
//    bool validateField(const enum myType&, const QString&);
//    bool validateRow(const QStringList&);
//    QString DelSpaces(const QString & s); //удалить незнач. пробелы
};

#endif // MYTABLE_H
