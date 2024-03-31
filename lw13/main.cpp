#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

void printFileContents(const string &filename) {
    ifstream file_in(filename);
    string line;
    if (file_in) {
        cout << "Содержимое файла `" << filename << "`:" << endl;
        while (getline(file_in, line)) {
            cout << line << endl;
        }
    } else {
        cerr << "Не удалось открыть файл для чтения." << endl;
    }
    cout << endl;
}

vector<string> readFileIntoVector(const string& filename) {
    ifstream file_in(filename);
    vector<string> lines;
    string line;
    if (!file_in) {
        throw runtime_error("Не удалось открыть файл для чтения: " + filename);
    }

    while (getline(file_in, line)) {
        lines.push_back(line);
    }
    return lines;
}

void writeVectorToFile(const vector<string>& lines, const string& filename) {
    ofstream file_out(filename);
    if (!file_out) {
        throw runtime_error("Не удалось открыть файл для записи: " + filename);
    }

    for (const auto& ln : lines) {
        file_out << ln << endl;
    }
}

void swapLinesInVector(vector<string>& lines, size_t line1_num, size_t line2_num) {
    if (line1_num > lines.size() || line2_num > lines.size() || line1_num == line2_num) {
        throw invalid_argument("Некорректные номера строк для обмена.");
    }

    swap(lines[line1_num - 1], lines[line2_num - 1]);
}

bool swapLines(const string& filename, size_t line1_num, size_t line2_num) {
    try {
        vector<string> lines = readFileIntoVector(filename);
        swapLinesInVector(lines, line1_num, line2_num);
        writeVectorToFile(lines, filename);
        return true;
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return false;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru-RU");

    string filename = "example.txt";

    printFileContents(filename);

    size_t line1, line2;

    cout << "Введите номера строк для обмена: " << endl;
    cin >> line1 >> line2;

    if (swapLines(filename, line1, line2)) {
        cout << "Строки успешно переставлены." << endl << endl;
        printFileContents(filename);
    } else {
        cerr << "Произошла ошибка при обмене строк." << endl;
    }

    return 0;
}
