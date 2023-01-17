#include "mainwindow.h"

MainWindow::MainWindow()
{
   this->setMinimumSize(1000, 400);
   QHBoxLayout *layout1 = new QHBoxLayout;
   QGridLayout* form = new QGridLayout;

   for (int i = 0; i < TYPES_OF_FIELD.size(); i++)
   {
       fields[i] = new Field(TYPES_OF_FIELD[i]);
   }
   date_field = new QDateEdit;

   QLabel* label[DATA_COUNT];
   QWidget* line_edit[] = {fields[0], fields[1], fields[2], fields[3], date_field, fields[4], fields[5]};
   for(int i = 0; i < DATA_COUNT; i++)
   {
       line_edit[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed); // Size policy
       line_edit[i]->setFont(QFont("system-ui", 12, 12)); // Set font
       label[i] = new QLabel(FIELD_LIST[i]);
       label[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed); // Size policy
       label[i]->setFont(QFont("system-ui", 12, 12)); // Set font
       form->addWidget(label[i], i, 0);
       form->addWidget(line_edit[i], i, 1, 1, 5);
   }
   layout1->addItem(form);

   //Buttons
   QPushButton* bt1 = new QPushButton(BUTTON_TITLES_1[0]);
   QPushButton* bt2 = new QPushButton(BUTTON_TITLES_1[1]);
   connect(bt1, SIGNAL(clicked()), this, SLOT(cleanData()));
   connect(bt2, SIGNAL(clicked()), this, SLOT(saveDataToTable()));

   bt1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
   bt2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);

   bt1->setFont(QFont("system-ui", 12, 12)); // Set font
   bt2->setFont(QFont("system-ui", 12, 12)); // Set font;

   QHBoxLayout* space = new QHBoxLayout();
   space->addSpacerItem(new QSpacerItem(1, 30, QSizePolicy::Expanding));
   form->addItem(space, DATA_COUNT, 0);
   form->addWidget(bt1,DATA_COUNT + 1, 0);
   form->addWidget(bt2,DATA_COUNT + 1, 1);

   // Set layout in QWidget
   QWidget *window1 = new QWidget();
   window1->setLayout(layout1);
   window1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

   QTabWidget *tabs = new QTabWidget();


   table = new MyTable();
   QHBoxLayout* layout2 = new QHBoxLayout();
   layout2->addWidget(table);
   QVBoxLayout* button_layout = new QVBoxLayout;
   QVector<QPushButton*> buttons;
   buttons.reserve(BUTTON_TITLES_2.size());
   for (const QString& title : BUTTON_TITLES_2)
   {
       QPushButton* b = new QPushButton(title);
       buttons.push_back(b);
       button_layout->addWidget(b);
   }

   button_layout->addSpacerItem(new QSpacerItem(1, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));

   connect(buttons[0], SIGNAL(clicked()), table, SLOT(addRow()));
   connect(buttons[1], SIGNAL(clicked()), table, SLOT(SortBySelectedColumn()));
   connect(buttons[2], SIGNAL(clicked()), table, SLOT(delRow()));
   connect(buttons[3], SIGNAL(clicked()), table, SLOT(exportDataToFILE()));
   connect(buttons[4], SIGNAL(clicked()), table, SLOT(importDataFromFILE()));
   connect(buttons[5], SIGNAL(clicked()), table, SLOT(cleanTable()));

   layout2->addItem(button_layout);
   QWidget *window2 = new QWidget();
   window2->setLayout(layout2);

   tabs->addTab(window1, "Форма");
   tabs->addTab(window2, "Таблица");

   // Set QWidget as the central layout of the main window
   setCentralWidget(tabs);
}

void MainWindow::saveDataToTable()
{
    //validate data
    for(int i = 0; i < DATA_COUNT - 1; i++)
    {
        if(!(fields[i]->isValid()))
        {
            return;
        }
    }

    //Insert data to table
    QStringList list;
    for (int i = 0; i <= 3; i++)
    {
        list << Field::DelDoubledSpaces(Field::DelSpacesBeforeAndAfter(\
                                            fields[i]->text()));
    }
    list << date_field->text();
    list << Field::DelAllSpaces(fields[4]->text());
    list << Field::DelAllNonNumbers(fields[5]->text());

    table->addDataRow(list);
    cleanData();

}

void MainWindow::cleanData()
{
    for (int i = 0; i < DATA_COUNT - 1; i++)
    {
        fields[i]->setText("");
    }
    date_field->setDate(QDate(2000, 1, 1));
}
