#include <iostream>
#include <typeinfo>
#include <map>
#include <iomanip>
#include <clocale>
using namespace std;

//Cписок месяцев
string month_order[12] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
//Список дней недели
string week_days[7] = { "Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс" };
//Список последних дней каждого месяца
map <string, unsigned> months;

//Функция для инициализации списка последних дней каждого месяца
void month_initialization() {
    // Словарь месяцев
    months["Январь"] = 31;
    months["Февраль"] = 28;
    months["Март"] = 31;
    months["Апрель"] = 30;
    months["Май"] = 31;
    months["Июнь"] = 30;
    months["Июль"] = 31;
    months["Август"] = 31;
    months["Сентябрь"] = 30;
    months["Октябрь"] = 31;
    months["Ноябрь"] = 30;
    months["Декабрь"] = 31;
}

//Функция для вычисления дня недели для конктретной даты
int get_dow(int Year, int Month, int Day)
{
    int a = (14 - Month) / 12;
    int y = Year - a;
    int m = Month + 12 * a - 2;
    int d = (7000 + (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7;
    return d ? d : 7;
}

//Функция для создания и вывода таблицы календаря
int table_creation(int year, int month) {
    //Количство дней, вязтых из словаря months с учетом високосного года для февраля
    int day_amount = months[month_order[month - 1]];
    if (year % 4 == 0 && month == 2) {
        day_amount = 29;
    }
    //День недели первого дня месяца
    int start_day = get_dow(year, month, 1);
    //Инициализация таблицы для вывода
    int table[7][5];
    //Заполнение первых дней недели до начальной даты месяца
    for (int i = 0; i < start_day; i++) {
        table[i][0] = 0;
    }
    int j = 0;
    //Заполнение таблицы днями
    for (int i = 1; i <= day_amount; i++) {
        if (get_dow(year, month, i) == 7) {
            table[get_dow(year, month, i) - 1][j] = i;
            j++;
        }
        else {
            table[get_dow(year, month, i) - 1][j] = i;
        }
    }
    //Вывод названия дней недели для таблицы
    for (int i = 0; i < 7; i++) {
        cout << week_days[i] << '\t';
    }
    cout << endl;
    //Вывод таблицы
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            if (table[j][i] >= 0) {
                if (table[j][i] == 0) {
                    cout << " " << '\t';
                }
                else {
                    cout << table[j][i] << '\t';
                }
            }
        }
        cout << endl;
    }
    return 0;
}

//Главная функция для начала программы
int main() {
    setlocale(LC_ALL, "Russian");
    //инициализации списка последних дней каждого месяца
    month_initialization();
    int month, year;
    //Цикл для проверки корректности введеных данных
    do {
        cout << "Введите месяц и год (мес: 1-12, год: 1919-2029" << endl;
        cin >> month >> year;
        if (month < 1 || month > 12 || year < 1919 || year > 2029) {
            cout << "Данные некоректны, проверьте написание";
        }
    } while (month < 1 || month > 12 || year < 1919 || year > 2029);
    //Вызов функции для создания и вывода таблицы календаря
    table_creation(year, month);
    return 0;
}
