#include <iostream>
#include <map>
#include <windows.h>

void removeDuplicates(char text[]) {
    std::map<char, bool> seen;
    int length = 0;
    int writeIndex = 0;

    while (text[length] != '\0') {
        if (seen.find(text[length]) == seen.end()) {
            seen[text[length]] = true;
            text[writeIndex++] = text[length];
        }
        length++;
    }

    text[writeIndex] = '\0';
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL,"ru-RU");

    const int max_length = 100;
    char text[max_length] = {}; // Array to read the string

    std::cout << "Введите текст (не более 100 символов):" << std::endl;
    std::cin.getline(text, max_length);

    removeDuplicates(text);

    std::cout << "Уникальные символы:" << std::endl;
    std::cout << text << std::endl;

    return 0;
}
