#include "mtable.h"

MyTable::MyTable() : changebleSortOrder(true), changeValidationStarted(false)
{
    setColumnCount(7);
    setHorizontalHeaderLabels(QStringList() << "Имя" << "Фамилия" << "Отчество" << "Адрес" << "Дата Рождения" << "Email" << "Телефон"); //(рабочий, домашний, служебный) в любом количестве
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setSelectionMode(QAbstractItemView::SingleSelection);

    connect(this, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(whenItemDoubleClicked(QTableWidgetItem*)));
//    connect(this, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(whenItemDoubleClicked(QTableWidgetItem*)));
    connect(this, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(whenItemChanged(QTableWidgetItem*)));
//    connect(this, SIGNAL(itemEntered(QTableWidgetItem*)), this, SLOT(whenItemChanged(QTableWidgetItem*)));
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
QStringList MyTable::getDataRow(const int& row)
{
    if(row >= 0 && row < rowCount())
    {
        QStringList list;
        for(int i = 0; i < columnCount(); i ++)
        {
            list << this->takeItem(row, i)->text();
        }
        return list;
    }
    throw std::out_of_range("Out of range");
}

void MyTable::cleanTable()
{
    for(int r = 0; r < rowCount(); r++)
    {
        for(int c = 0; c < columnCount(); c++)
        {
            delete this->takeItem(r, c);
        }
    }
    setRowCount(0);
}

void MyTable::whenItemDoubleClicked(QTableWidgetItem *item)
{
    //Save prev value
    cell_Data_buffer = item->text();
    changeValidationStarted = true;
}

void MyTable::whenItemChanged(QTableWidgetItem *item)
{
    if(!changeValidationStarted) return;

    //validate
    DataValidator d;
    fieldType type;
    switch (item->column())
    {
    case 0:
    case 1:
    case 2:
        type = fieldType::Name;
        break;
    case 3:
        type = fieldType::Address;
        break;
    case 4:
        type = fieldType::Date;
        break;
    case 5:
        type = fieldType::Email;
        break;
    case 6:
        type = fieldType::PhoneTable;
        break;
    }

    bool isValid = d(type, item->text());

    if(!isValid)
    {
        item->setText(cell_Data_buffer);
    }
    changeValidationStarted = false;
}

void MyTable::SortBySelectedColumn()
{
    if(this->selectedRanges().size() == 1 && this->selectedRanges().at(0).columnCount() == 1)
    {
        Qt::SortOrder s = changebleSortOrder ? Qt::SortOrder::AscendingOrder : Qt::SortOrder::DescendingOrder;
        this->sortByColumn(this->selectedRanges().at(0).leftColumn(), s);
        changebleSortOrder = 1 - changebleSortOrder;
    }
}

void MyTable::addRow()
{
    //Add empty row at the end
    setRowCount(rowCount() + 1);
    for(int i = 0; i < columnCount(); i++)
    {
        setItem(rowCount() - 1, i, new QTableWidgetItem("EMPTY"));
    }

    if(this->selectedRanges().size() == 1 && this->selectedRanges().at(0).rowCount() == 1)
    {
        int rowNum = this->selectedRanges().at(0).topRow() + 1;
        QTableWidgetItem* cur;

        for(int c = 0; c < columnCount(); c++)
        {
            // save rowNum in cur and create new empty row
            cur = takeItem(rowNum, c);
            setItem(rowNum, c, new QTableWidgetItem("EMPTY"));
//            this->setItem(rowNum, c)
//            itemAt(rowNum, c)->setText("EMPTY");

            for(int r = rowNum + 1; r < rowCount(); r++)
            {
                QTableWidgetItem* tmp = takeItem(r, c);
                setItem(r, c, cur);
                cur = tmp;
            }
        }
    }
}

void MyTable::delRow()
{
    if(this->selectedRanges().size() == 1 && this->selectedRanges().at(0).rowCount() == 1) // if 1 row selected
    {
        int rowNum = this->selectedRanges().at(0).topRow();
        for(int c = 0; c < columnCount(); c++)
        {
            for(int r = rowNum; r < rowCount(); r++)
            {
                setItem(r, c, takeItem(r + 1, c));
            }
            delete takeItem(rowCount(), c);
        }
        setRowCount(rowCount() - 1);
    }
    else if(this->rowCount() > 0) //Nothing is selected or smt not valid
    {
        //del last row
        for(int c = 0; c < columnCount(); c++)
        {
            delete takeItem(rowCount(), c);
        }
        setRowCount(rowCount() - 1);
    }
}

void MyTable::exportDataToFILE()
{
    QFile file("D:\\repos\\Lab8\\DATA.txt"); // Связываем объект с файлом
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;




    QTextStream out(&file);
    QString tmp = "";

    for(int r = 0; r < this->rowCount(); r++)
    {
        // Check that in table there is no empty cells
        QStringList row = this->getDataRow(r);
        if (row.count() == 0)
        {
            file.close();
            return;
        }

        tmp += row.join("&");
        tmp += "\n";
    }

    out << tmp;
    file.close();

    cleanTable();

}

void MyTable::importDataFromFILE()
{
    cleanTable();
    QFile file("D:\\repos\\Lab8\\DATA.txt");
   if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       return;

   QTextStream in(&file);
   while (!in.atEnd())
   {
       QString line = in.readLine();
       QStringList l = line.split("&");
       addDataRow(l);
   }
}
