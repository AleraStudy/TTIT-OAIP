#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru-RU");

    double x, y, f;

    cout << "Введите x: ";
    cin >> x;

    cout << "Введите y: ";
    cin >> y;

    if (y == 0) {
        cout << "Ошибка, y не должен быть равен нулю";
        return 1;
    }

    int k;
    cout << "Введите f: 1 - sh(x), 2 - x^2, 3 – exp(x) ";
    cin >> k;

    switch (k) {
        case 1:
            f = sinh(x);
            break;
        case 2:
            f = pow(x, 2);
            break;
        case 3:
            f = exp(x);
            break;
        default:
            cout << "Функция не выбрана";
            return 1;
    }

    double xy = x / y;
    double b;

    if (xy > 0) {
        b = f + pow(log(y), 3);
    } else if (xy < 0) {
        b = 2.0 / 3 + log(abs(sin(y)));
    } else {
        b = pow(pow(x, 2), 1.0 / 3) + y;
    }

    cout << "Результат b = " << b << endl;

    return 0;
}