#include "mainwindow.h"

#include <QApplication>
#include <QTableView>
#include <QTableWidget>
#include <mytable.h>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    MainWindow w;
    w.show();

    return a.exec();
}
