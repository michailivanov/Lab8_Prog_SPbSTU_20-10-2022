#include "mytable.h"

MyTable::MyTable()
{
    setColumnCount(7);
    setRowCount(10);

    setHorizontalHeaderLabels(QStringList() << "Имя" << "Фамилия" << "Отчество" << "Адрес" << "Дата Рождения" << "Email" << "Телефон"); //(рабочий, домашний, служебный) в любом количестве
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    for(int i = 0; i < rowCount(); i++)
    {
//        QString::number(s)
        QTableWidgetItem* item = new QTableWidgetItem("Михаил");
        setItem(i, 0, item);
        item = new QTableWidgetItem("Иванов");
        setItem(i, 1, item);
        item = new QTableWidgetItem("-");
        setItem(i, 2, item);
        item = new QTableWidgetItem("Политехническая улица, д. 29");
        setItem(i, 3, item);
        item = new QTableWidgetItem("08.08.1888");
        setItem(i, 4, item);
        item = new QTableWidgetItem("test@gmail.com");
        setItem(i, 5, item);
        item = new QTableWidgetItem("+78121234567");
        setItem(i, 6, item);
    }
    //    show();
}


void MyTable::addDataRow(const QStringList & sl)
{
    setRowCount(rowCount() + 1);

    QTableWidgetItem* item;
    for(int i = 0; i < columnCount(); i++)
    {
        item = new QTableWidgetItem(sl.at(i));
        setItem(rowCount() - 1, i, item);
    }
}

//void MyTable::toRed(const int & x, const int & y)
//{
//    this->itemAt(x, y)->setBackgroundColor(Qt::GlobalColor::red);
//}

//void MyTable::toGreen(const int & x, const int & y)
//{
//    this->itemAt(x, y)->setBackgroundColor(Qt::GlobalColor::green);
//}

//void MyTable::toGray(const int & x, const int & y)
//{
//    this->itemAt(x, y)->setBackgroundColor(Qt::GlobalColor::gray);
//}

void MyTable::SortBySelectedColumn()
{
    if(this->selectedRanges().at(0).columnCount() == 1)
    {
        Qt::SortOrder s = changebleSortOrder ? Qt::SortOrder::AscendingOrder : Qt::SortOrder::DescendingOrder;
        this->sortByColumn(this->selectedRanges().at(0).leftColumn(), s);
        changebleSortOrder = 1 - changebleSortOrder;
    }
}

