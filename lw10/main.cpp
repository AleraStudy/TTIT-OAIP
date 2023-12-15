#include <iostream>
#include <windows.h>

using namespace std;

int recursiveMultiply(int a, int b) {
    if (b == 0) return 0;
    if (b == 1) return a;

    if (b % 2 == 0) {
        return 2 * recursiveMultiply(a, b / 2);
    }
    else {
        return a + recursiveMultiply(a, b - 1);
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru-RU");

    int a, b;

    cout << "Введите два положительных целых числа: " << endl;
    cin >> a >> b;

    cout << "Результат: " << recursiveMultiply(a, b) << endl;

    return 0;
}
