#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL,"ru-RU");

    int n, m;
    cout << "Введите размеры матрицы N и M: ";
    cin >> n >> m;

    // Dynamic memory allocation
    const auto matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }

    // Fill the matrix with random numbers
    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 100;
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }

    // Find the maximum below the secondary diagonal and the minimum above the main diagonal
    int maxBelowSecondaryDiag = INT_MIN;
    int minAboveMainDiag = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Below the secondary diagonal
            if (i + j > m - 1) {
                if (matrix[i][j] > maxBelowSecondaryDiag) {
                    maxBelowSecondaryDiag = matrix[i][j];
                }
            }
            // Above the main diagonal
            if (j > i) {
                if (matrix[i][j] < minAboveMainDiag) {
                    minAboveMainDiag = matrix[i][j];
                }
            }
        }
    }

    cout << "Максимальный элемент ниже побочной диагонали: " << maxBelowSecondaryDiag << endl;
    cout << "Минимальный элемент выше главной диагонали: " << minAboveMainDiag << endl;

    // Free memory
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
