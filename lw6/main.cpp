#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include <locale>
#include <codecvt>
#include <windows.h>

using namespace std;

bool isVowel(wchar_t c) {
    const wstring vowels = L"aeiouAEIOUаеёиоуыэюяАЕЁИОУЫЭЮЯ";
    return vowels.find(c) != wstring::npos;
}

bool checkIsVowelContains(const wstring& word) {
    return any_of(word.begin(), word.end(), isVowel);
}

vector<wstring> splitIntoWords(const wstring& text) {
    wstringstream ss(text);
    vector<wstring> words;
    wstring word;

    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}

int main() {
    // Включаем поддержку UTF-8
    locale::global(locale(locale::classic(), new codecvt_utf8<wchar_t>));
    wcin.imbue(locale());
    wcout.imbue(locale());

    SetConsoleOutputCP(CP_UTF8);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    do {
        wstring text;
        wcout << L"Введите несколько слов:\n" << flush;
        getline(wcin, text);

        for (wchar_t c: text) {
            bool isVowelChar = isVowel(c);
            if (!isVowelChar) {
                int a = 1;
            }
            wcout << c << L" " << (isVowelChar ? "- vovel" : "- not vowel") << "\n";
        }

        vector<wstring> words = splitIntoWords(text);
        auto const wordsCount = words.size();

        if (wordsCount < 1) {
            wcout << L"Не нашлось ни одного слова!\n";
            continue;
        }

        int wordNumber;
        wcout << L"Введите номер слова для проверки на гласные (от 1 до " << wordsCount << L"):\n" << flush;
        wcin >> wordNumber;

        // Очистка и синхронизация потока ввода
        wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
        wcin.clear();

        if (wordNumber > 0 && wordNumber <= wordsCount) {
            bool isVowelContains = checkIsVowelContains(words[wordNumber - 1]);
            cout << (isVowelContains ? "Есть гласные" : "Нет гласных") << endl;
        } else {
            wcout << L"Неверный номер слова!\n";
            continue;
        }

    } while (false);

    return 0;
}
