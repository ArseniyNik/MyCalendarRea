#include <iostream>
#include <typeinfo>
#include <map>
#include <iomanip>
#include <clocale>
using namespace std;

//C����� �������
string month_order[12] = { "������", "�������", "����", "������", "���", "����", "����", "������", "��������", "�������", "������", "�������" };
//������ ���� ������
string week_days[7] = { "��", "��", "��", "��", "��", "��", "��" };
//������ ��������� ���� ������� ������
map <string, unsigned> months;

//������� ��� ������������� ������ ��������� ���� ������� ������
void month_initialization() {
    // ������� �������
    months["������"] = 31;
    months["�������"] = 28;
    months["����"] = 31;
    months["������"] = 30;
    months["���"] = 31;
    months["����"] = 30;
    months["����"] = 31;
    months["������"] = 31;
    months["��������"] = 30;
    months["�������"] = 31;
    months["������"] = 30;
    months["�������"] = 31;
}

//������� ��� ���������� ��� ������ ��� ����������� ����
int get_dow(int Year, int Month, int Day)
{
    int a = (14 - Month) / 12;
    int y = Year - a;
    int m = Month + 12 * a - 2;
    int d = (7000 + (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7;
    return d ? d : 7;
}

//������� ��� �������� � ������ ������� ���������
int table_creation(int year, int month) {
    //��������� ����, ������ �� ������� months � ������ ����������� ���� ��� �������
    int day_amount = months[month_order[month - 1]];
    if (year % 4 == 0 && month == 2) {
        day_amount = 29;
    }
    //���� ������ ������� ��� ������
    int start_day = get_dow(year, month, 1);
    //������������� ������� ��� ������
    int table[7][5];
    //���������� ������ ���� ������ �� ��������� ���� ������
    for (int i = 0; i < start_day; i++) {
        table[i][0] = 0;
    }
    int j = 0;
    //���������� ������� �����
    for (int i = 1; i <= day_amount; i++) {
        if (get_dow(year, month, i) == 7) {
            table[get_dow(year, month, i) - 1][j] = i;
            j++;
        }
        else {
            table[get_dow(year, month, i) - 1][j] = i;
        }
    }
    //����� �������� ���� ������ ��� �������
    for (int i = 0; i < 7; i++) {
        cout << week_days[i] << '\t';
    }
    cout << endl;
    //����� �������
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

//������� ������� ��� ������ ���������
int main() {
    setlocale(LC_ALL, "Russian");
    //������������� ������ ��������� ���� ������� ������
    month_initialization();
    int month, year;
    //���� ��� �������� ������������ �������� ������
    do {
        cout << "������� ����� � ��� (���: 1-12, ���: 1919-2029" << endl;
        cin >> month >> year;
        if (month < 1 || month > 12 || year < 1919 || year > 2029) {
            cout << "������ ����������, ��������� ���������";
        }
    } while (month < 1 || month > 12 || year < 1919 || year > 2029);
    //����� ������� ��� �������� � ������ ������� ���������
    table_creation(year, month);
    return 0;
}
