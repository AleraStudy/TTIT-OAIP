#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std;

struct Train {
    int day;
    string destination;
    int time;
    int seats;
};

int findSuitableTrain(Train trains[], int size, int day, const string& destination, int time, int seats) {
    for (int i = 0; i < size; i++) {
        if (trains[i].day == day && trains[i].destination == destination && trains[i].time <= time && trains[i].seats >=
            seats) {
            return i;
        }
    }
    return -1;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Train trains[] = {
        {1, "Moscow", 18, 100},
        {1, "Kazan", 19, 80},
        {1, "Kazan", 20, 60},
        {4, "Sochi", 17, 50},
        {5, "Ufa", 19, 70},
        {5, "Omsk", 16, 90},
        {5, "Ufa", 18, 100},
        {5, "Ufa", 20, 80},
        {5, "Ufa", 22, 60},
        {5, "Sochi", 24, 40},
        {5, "Ufa", 23, 150},
    };

    cout << "Информация об имеющихся поездах (данные дня оператора):" << endl;
    cout << left << setw(5) << "N" << setw(15) << "Route" << setw(10) << "Day" << setw(10) << "Time" << setw(10) <<
            "Seats" << endl;

    constexpr int trainEntriesCount = size(trains);

    for (int i = 0; i < trainEntriesCount; i++) {
        cout << left << setw(5) << i + 1 << setw(15) << trains[i].destination << setw(10) << trains[i].day << setw(10)
                << trains[i].time << setw(10) << trains[i].seats << endl;
    }

    int day, time, seats;
    string destination;

    cout << endl;
    cout << "Сообщите требуемую дату отправления (номер для недели от 1 до 7): " << endl;
    cin >> day;
    cout << "Введите название пункта назначения: " << endl;
    cin >> destination;
    cout << "Укажите крайнее допустимое время отправления (t часов вечера): " << endl;
    cin >> time;
    cout << "Укажите количество требуемых мест: " << endl;
    cin >> seats;

    const int trainIndex = findSuitableTrain(trains, trainEntriesCount, day, destination, time, seats);

    if (trainIndex != -1) {
        cout << "Нашёлся подходящий рейс: №" << trainIndex + 1 << ", следующий в пункт " << trains[trainIndex].destination <<
                ", отправление в " << trains[trainIndex].time << endl;
    } else {
        cout << "Место не найдено" << endl;
    }

    return 0;
}
