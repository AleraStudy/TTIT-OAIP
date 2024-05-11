#include <iostream>
#include <limits>
#include <windows.h>

using namespace std;

// Определение структуры узла
struct Node {
    int value;  // Значение, хранящееся в узле
    Node* next; // Указатель на следующий узел в списке

    // Конструктор для инициализации узла
    explicit Node(int val) : value(val), next(nullptr) {}
};

// Определение структуры стека
struct Stack {
    Node* top; // Указатель на вершину стека

    // Конструктор для инициализации стека
    Stack() : top(nullptr) {}

    // Функция для добавления элемента в стек
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Функция для удаления элемента из стека
    int pop() {
        if (isEmpty()) {
            cerr << "Стек пуст" << endl;
            return -1;
        }
        Node* temp = top;
        int poppedValue = top->value;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    // Проверка пуст ли стек
    [[nodiscard]] bool isEmpty() const {
        return top == nullptr;
    }
};

int findMin(Stack& stack) {
    if (stack.isEmpty()) {
        cerr << "Стек пуст" << endl;
        return -1;
    }

    int min = numeric_limits<int>::max();
    Stack tempStack;

    while (!stack.isEmpty()) {
        int current = stack.pop();
        if (current < min) {
            min = current;
        }
        tempStack.push(current);
    }

    // Возвращаем элементы обратно в исходный стек
    while (!tempStack.isEmpty()) {
        stack.push(tempStack.pop());
    }

    return min;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru-RU");

    Stack stack;
    string input;

    cout << "Введите элементы стека (целые числа). Для завершения ввода введите 'q':" << endl;

    while (true) {
        cout << "Элемент стека: ";
        cin >> input;

        if (input == "q" || input == "Q") {
            break;
        }

        try {
            int value = stoi(input);
            stack.push(value);
        }
        catch (const invalid_argument& e) {
            cerr << "Ошибка ввода. Введите целое число или 'q' для завершения." << endl;
        }
    }

    if (stack.isEmpty()) {
        cout << "Стек пуст. Наименьший элемент не найден." << endl;
    }
    else {
        int min = findMin(stack);
        cout << "Наименьший элемент: " << min << endl;
    }

    return 0;
}
