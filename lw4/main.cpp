#include <iostream>
#include <map>
#include <windows.h>

void removeDuplicates(char text[]) {
    std::map<char, bool> seen;
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

    constexpr int max_length = 100;
    char text[max_length] = {};

    std::cout << "Введите текст (не более 100 символов):" << std::endl;
    std::cin.getline(text, max_length);

    removeDuplicates(text);

    std::cout << "Уникальные символы:" << std::endl;
    std::cout << text << std::endl;

    return 0;
}
