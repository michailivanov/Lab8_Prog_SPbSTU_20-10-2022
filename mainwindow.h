#pragma once

#include "mtable.h"
#include "fieldlineedit.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDateEdit>
#include <QTabWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Field* fields[DATA_COUNT - 1];
    QDateEdit* date_field;
    MyTable* table;
public:
    MainWindow();
public slots:
    void saveDataToTable();
    void cleanData();
};
