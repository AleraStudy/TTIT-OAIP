#include <iostream>
#include <windows.h>

using namespace std;

// Определение структуры узла
struct Node {
    int data;     // Данные, хранящиеся в узле
    Node* prev;   // Указатель на предыдущий узел
    Node* next;   // Указатель на следующий узел
};

// Класс, представляющий очередь на базе двусвязного списка
class Queue {
private:
    Node* front;  // Указатель на первый элемент очереди
    Node* rear;   // Указатель на последний элемент очереди

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Функция для добавления элемента в очередь
    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    // Функция для удаления элемента из очереди
    void dequeue() {
        if (isEmpty()) {
            cout << "Очередь пуста. Удаление невозможно." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        } else {
            front->prev = nullptr;
        }

        delete temp;
    }

    // Функция для получения первого элемента очереди
    int peek() {
        if (isEmpty()) {
            cout << "Очередь пуста." << endl;
            return -1;
        }

        return front->data;
    }

    // Функция для проверки, пуста ли очередь
    bool isEmpty() {
        return front == nullptr;
    }

    // Функция для отображения элементов очереди
    void display() {
        if (isEmpty()) {
            cout << "Очередь пуста." << endl;
            return;
        }

        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru-RU");

    Queue queue;
    string input;

    cout << "Введите элементы очереди (целые числа). Для завершения ввода введите 'q':" << endl;

    while (true) {
        cout << "Элемент очереди: ";
        cin >> input;

        if (input == "q" || input == "Q") {
            break;
        }

        try {
            int value = stoi(input);
            queue.enqueue(value);
        }
        catch (const invalid_argument& e) {
            cerr << "Ошибка ввода. Введите целое число или 'q' для завершения." << endl;
        }
    }

    cout << "Очередь: ";
    queue.display();

    cout << "Первый элемент очереди: " << queue.peek() << endl;

    cout << "Пример операции с очередью: Удаление элемента из очереди." << endl;
    queue.dequeue();

    cout << "Очередь после удаления: ";
    queue.display();

    return 0;
}
