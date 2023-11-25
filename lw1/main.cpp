#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL,"ru-RU");

    double x, y, z;

    cout << "Введите x: ";
    cin >> x;

    cout << "Введите y: ";
    cin >> y;

    cout << "Введите z: ";
    cin >> z;

    double numerator = pow(y + cbrt(x - 1.0), 1.0/4);
    double denominator = abs(x - y) * (pow(sin(z), 2) + tan(z));
    double s = numerator / denominator;

    cout << "Результат s = " << s << endl;

    return 0;
}