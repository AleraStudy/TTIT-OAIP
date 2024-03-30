#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "StringLibrary.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru-RU");

    string text = "The quick brown and fox jumps over-the lazy dog. The fox dashes across the field, chasing a rabbit. The dog wakes up from its nap and watches the fox's movements.  and";
    cout << "Исходная строка:" << endl << text << endl;
    cout << endl;

    string substr = "the";
    cout << "Количество вхождений подстроки '" << substr << "' в строку: " << substringOccurrences(text, substr)
         << endl;
    substr = "The";
    cout << "Количество вхождений подстроки '" << substr << "' в строку: " << substringOccurrences(text, substr)
         << endl;
    cout << endl;

    char delimiter = '.';
    vector<string> tokens = splitString(text, delimiter);
    cout << "Токены после разделения строки по '" << delimiter << "': " << endl;
    int i = 1;
    for (const auto &token: tokens) {
        cout << i++ << ": " << token << endl;
    }
    cout << endl;

    vector<string> uniqueWords = findUniqueWords(text);
    cout << "Уникальные слова в строке: " << endl;
    i = 1;
    for (const auto &word: uniqueWords) {
        cout << i++ << ": " << word << endl;
    }
    cout << endl;

    return 0;
}