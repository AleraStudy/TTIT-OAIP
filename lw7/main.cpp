#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

struct Train {
    int day;
    string destination;
    int time;
    int seats;
};

int main() {
    SetConsoleOutputCP(CP_UTF8);

    // Моки для начальных данных
    Train trains[] = {
        {1, "Moscow", 18, 100},
        {1, "Kazan", 19, 80},
        {1, "Kazan", 20, 60},
        {4, "Sochi", 17, 50},
        {5, "Ufa", 19, 70},
        {5, "Omsk", 16, 90},
        {5, "Ufa", 18, 100},
        {5, "Novosib", 20, 80},
        {5, "Ufa", 22, 60},
        {5, "Sochi", 24, 40}
    };

    cout << "Информация об имеющихся поездах (данные дня оператора):" << endl;
    cout << left << setw(5) << "N" << setw(15) << "Route" << setw(10) << "Day" << setw(10) << "Time" << setw(10) << "Seats" << endl;

    // Вывод информации об имеющихся поездах
    for (int i = 0; i < 10; i++) {
        cout << left << setw(5) << i + 1 << setw(15) << trains[i].destination << setw(10) << trains[i].day << setw(10) << trains[i].time << setw(10) << trains[i].seats << endl;
    }

    // Ввод данных
    int day, time, seats;
    string destination;


    cout << endl;
    cout << "Сообщите требуемую дату отправления (номер для недели от 1 до 7): "<< endl;
    cin >> day;
    cout << "Введите название пункта назначения: "<< endl;
    cin >> destination;
    cout << "Укажите крайнее допустимое время отправления (t часов вечера): "<< endl;
    cin >> time;
    cout << "Укажите количество требуемых мест: "<< endl;
    cin >> seats;

    for (int i = 0; i < 3; i++) {
        if (trains[i].day == day && trains[i].destination == destination) {
            if (trains[i].seats >= seats) {
                // Нашлось подходящее место
                cout << "Нашёлся подходящий рейс: №" << i + 1 << " по в пункт " << trains[i].destination << ", отправление в " << trains[i].time << endl;
                return 0;
            }
        }
    }

    cout << "Место не найдено" << endl;
    return 0;
}
