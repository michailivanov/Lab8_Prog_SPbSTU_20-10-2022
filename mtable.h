#ifndef MYTABLE_H
#define MYTABLE_H

#include <QTableWidget>
#include <QFile>
#include <QTextStream>
#include "datavalidator.h"

class MyTable : public QTableWidget
{
    Q_OBJECT
    bool changebleSortOrder;
    bool changeValidationStarted;
    QString cell_Data_buffer;
    QStringList getDataRow(const int& i);
public:
    MyTable();
    void addDataRow(const QStringList&);
public slots:
    void SortBySelectedColumn();
    void addRow();
    void delRow();
    void exportDataToFILE();
    void importDataFromFILE();
    void cleanTable();
    void whenItemDoubleClicked(QTableWidgetItem* item);
    void whenItemChanged(QTableWidgetItem* item);
};

#endif // MYTABLE_H
