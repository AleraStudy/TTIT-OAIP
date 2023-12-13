#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

bool checkIsVowelContains(const string& word) {
    const string vowels = "aeiouAEIOUаеёиоуыэюяАЕЁИОУЫЭЮЯ";
    return any_of(word.begin(), word.end(), [&](char c) {
        return vowels.find(c) != string::npos;
    });
}

vector<string> splitIntoWords(const string& text) {
    stringstream ss(text);
    vector<string> words;
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL,"ru-RU");

    string text;
    cout << "Введите несколько слов:\n";
    getline(cin, text);

    vector<string> words = splitIntoWords(text);
    auto const wordsCount = words.size();

    if (wordsCount < 1) {
        cout << "Не нашлось ни одного слова!";
        return 1;
    }

    int wordNumber;
    cout << "Введите номер слова для проверки на гласные (от 1 до " << wordsCount << "):\n";
    cin >> wordNumber;
    if (wordNumber > 0 && wordNumber <= wordsCount) {
        bool isVovewContains = checkIsVowelContains(words[wordNumber - 1]);
        cout << (isVovewContains ? "Есть гласные" : "Нет гласных") << endl;
    } else {
        cout << "Неверный номер слова!";
        return 1;
    }

    return 0;
}