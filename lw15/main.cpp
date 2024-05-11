#include <iostream>
#include <queue>
#include <windows.h>

using namespace std;

void filterEvenNumbers(queue<int>& q) {
    queue<int> tempQueue;

    while (!q.empty()) {
        int currentNumber = q.front();
        q.pop();

        if (currentNumber % 2 == 0) {
            tempQueue.push(currentNumber);
        }
    }

    q = tempQueue;
}

void readQueueInput(queue<int>& q) {
    cout << "Введите элементы очереди (целые числа). Для завершения ввода введите 'q':" << endl;
    string input;

    while (true) {
        cout << "Элемент очереди:" << endl;
        cin >> input;

        if (input == "q" || input == "Q") {
            break;
        }

        try {
            int value = stoi(input);
            q.push(value);
        }
        catch (const invalid_argument& e) {
            cerr << "Ошибка ввода. Введите целое число или 'q' для завершения." << endl;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru-RU");

    queue<int> myQueue;
    readQueueInput(myQueue);

    cout << "Исходная очередь: ";
    queue<int> originalQueue = myQueue;
    while (!originalQueue.empty()) {
        cout << originalQueue.front() << " ";
        originalQueue.pop();
    }
    cout << endl;

    filterEvenNumbers(myQueue);

    cout << "Отфильтрованная очередь (только четные числа): ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;

    return 0;
}
