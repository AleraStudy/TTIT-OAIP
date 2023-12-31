#include <iostream>
#include <map>
#include <windows.h>
using namespace std;

void removeDuplicates(char text[]) {
    map<char, bool> seen;
    int readIndex = 0;
    int writeIndex = 0;

    while (text[readIndex] != '\0') {
        auto it = seen.find(text[readIndex]);
        auto end = seen.end();
        const bool isCharacterUnique = it == end;

        if (isCharacterUnique) {
            seen[text[readIndex]] = true;
            text[writeIndex] = text[readIndex];
            writeIndex++;
        }
        readIndex++;
    }

    text[writeIndex] = '\0';
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL,"ru-RU");

    constexpr int maxLength = 100;
    char text[maxLength] = {};

    cout << "Введите текст (не более 100 символов):" << endl;
    cin.getline(text, maxLength);

    removeDuplicates(text);

    cout << "Уникальные символы:" << endl;
    cout << text << endl;

    return 0;
}
