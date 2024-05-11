#include <iostream>
#include <windows.h>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

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

    int peek() {
        if (isEmpty()) {
            cout << "Очередь пуста." << endl;
            return -1;
        }

        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

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

void readQueueInput(Queue& queue) {
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
            queue.enqueue(value);
        } catch (const invalid_argument& e) {
            cerr << "Ошибка ввода. Введите целое число или 'q' для завершения." << endl;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru-RU");

    Queue queue;
    readQueueInput(queue);

    cout << "Очередь: ";
    queue.display();

    cout << "Первый элемент очереди: " << queue.peek() << endl;

    cout << "Пример операции с очередью: Удаление элемента из очереди." << endl;
    queue.dequeue();

    cout << "Очередь после удаления: ";
    queue.display();

    return 0;
}
