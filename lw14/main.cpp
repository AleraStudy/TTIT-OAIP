#include <iostream>
#include <limits>
#include <windows.h>

using namespace std;

struct Node {
    int value;
    Node* next;
    explicit Node(int val) : value(val), next(nullptr) {}
};

struct Stack {
    Node* top;
    Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

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

    while (!tempStack.isEmpty()) {
        stack.push(tempStack.pop());
    }

    return min;
}

void readStackInput(Stack& stack) {
    cout << "Введите элементы стека (целые числа). Для завершения ввода введите 'q':" << endl;
    string input;

    while (true) {
        cout << "Элемент стека:" << endl;
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
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru-RU");

    Stack stack;
    readStackInput(stack);

    if (stack.isEmpty()) {
        cout << "Стек пуст. Наименьший элемент не найден." << endl;
    } else {
        int min = findMin(stack);
        cout << "Наименьший элемент: " << min << endl;
    }

    return 0;
}
