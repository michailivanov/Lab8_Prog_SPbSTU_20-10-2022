#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QString>
#include <QVector>

enum fieldType { Name, Address, Email, Phone, Date, PhoneTable};
const QVector<QString> REG = { "^([a-zA-Zа-яА-я][a-zA-Zа-яА-я- ]*)?[a-zA-Zа-яА-я]$",\
                               "^([a-zA-Zа-яА-я0-9][a-zA-Zа-яА-я- 0-9]*)?[a-zA-Zа-яА-я0-9]$",\
                               "^((?!\\.)[\\w\\-_.]*)(@\\w+)(\\.\\w+(\\.\\w+)?[^.\\W])$", \
                               "^^[+]?[0-9 ()-]{3,20}$",\
                               "^[0-9][0-9].[0-9][0-9].[0-9][0-9][0-9][0-9]$",\
                               "^[0-9]{3,18}$"};
const int DATA_COUNT = 7;
const QVector<fieldType> TYPES_OF_FIELD = { fieldType::Name, fieldType::Name, fieldType::Name, fieldType::Address, fieldType::Email, fieldType::Phone };
const QString FIELD_LIST[] = { "Имя", "Фамилия", "Отчество", "Адрес", "Дата Рождения", "Email", "Телефон" };
const QVector<QString> BUTTON_TITLES_1 = {"Очистить данные", "Ввод данных"};
const QVector<QString> BUTTON_TITLES_2 = { "Добавить строку", "Сортировать по выбранной колонке", "Удалить строку", "Экспорт в файл", "Импорт из файла", "Очистить таблицу"};

#endif // CONSTANTS_H
