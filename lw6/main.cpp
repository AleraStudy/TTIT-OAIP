#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <locale>
#include <windows.h>

using namespace std;

bool isVowel(char c) {
    const string vowels = "aeiouyAEIOUY";
    return vowels.find(c) != string::npos;
}

bool checkIsVowelContains(const string& word) {
    return any_of(word.begin(), word.end(), isVowel);
}

vector<string> splitStringToWords(const string& text) {
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

    string text;
    cout << "Введите несколько слов (только латиница):" << endl;
    getline(cin, text);

    vector<string> words = splitStringToWords(text);
    auto const wordsCount = words.size();

    if (wordsCount < 1) {
        cout << "Не нашлось ни одного слова!\n";
        return 1;
    }

    int wordNumber;
    cout << "Введите номер слова для проверки на гласные (от 1 до " << wordsCount << "):" << endl;
    cin >> wordNumber;

    if (wordNumber > 0 && wordNumber <= wordsCount) {
        bool isVowelContains = checkIsVowelContains(words[wordNumber - 1]);
        cout << (isVowelContains ? "Есть гласные" : "Нет гласных") << endl;
    } else {
        cout << "Неверный номер слова!\n";
        return 1;
    }

    return 0;
}
