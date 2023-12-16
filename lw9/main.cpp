#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
using namespace std;

int** createAndFillMatrix(const int n, const int m) {
    const auto matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 100;
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    return matrix;
}

void findMaxMinElements(const int** matrix, const int n, const int m, int& maxBelow, int& minAbove) {
    maxBelow = INT_MIN;
    minAbove = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + j > m - 1 && matrix[i][j] > maxBelow) {
                maxBelow = matrix[i][j];
            }
            if (j > i && matrix[i][j] < minAbove) {
                minAbove = matrix[i][j];
            }
        }
    }
}

void freeMatrixMemory(int** matrix, const int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru-RU");

    int n, m;
    cout << "Введите размеры матрицы N и M: " << endl;
    cin >> n >> m;

    int** matrix = createAndFillMatrix(n, m);

    int maxBelowSecondaryDiag, minAboveMainDiag;
    findMaxMinElements((const int**)matrix, n, m, maxBelowSecondaryDiag, minAboveMainDiag);

    cout << "Максимальный элемент ниже побочной диагонали: ";
    if (n > 1)
    {
        cout << maxBelowSecondaryDiag << endl;
    } else {
        cout << "некорректный размер матрицы" << endl;
    }

    cout << "Минимальный элемент выше главной диагонали: ";
    if (m > 1)
    {
        cout << minAboveMainDiag << endl;
    } else {
        cout << "некорректный размер матрицы" << endl;
    }

    freeMatrixMemory(matrix, n);

    return 0;
}
