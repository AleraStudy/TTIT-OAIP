#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <windows.h>
#include <cctype>

using namespace std;

int substringOccurrences(const string &str, const string &substr) {
    int count = 0;
    size_t pos = 0;
    while ((pos = str.find(substr, pos)) != string::npos) {
        count++;
        pos += substr.length();
    }
    return count;
}

vector<string> splitString(const string &str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<string> findUniqueWords(const string& str) {
    unordered_set<string> wordSet;
    vector<string> uniqueWords;
    string word;
    istringstream iss(str);
    while (iss >> word) {
        string lowercaseWord;
        for (char c : word) {
            if (isalpha(c) || c == '-') {
                lowercaseWord += tolower(c);
            }
        }
        if (wordSet.find(lowercaseWord) == wordSet.end()) {
            wordSet.insert(lowercaseWord);
            uniqueWords.push_back(lowercaseWord);
        }
    }
    return uniqueWords;
}

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