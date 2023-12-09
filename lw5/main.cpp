#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL,"ru-RU");

    int N, M;
    cout << "Введите размеры матрицы N и M: ";
    cin >> N >> M;

    // Dynamic memory allocation
    const auto matrix = new int*[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[M];
    }

    // Fill the matrix with random numbers
    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = rand() % 100;
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }

    // Find the maximum below the secondary diagonal and the minimum above the main diagonal
    int max_below_secondary_diag = INT_MIN;
    int min_above_main_diag = INT_MAX;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // Below the secondary diagonal
            if (i + j > M-1) {
                if (matrix[i][j] > max_below_secondary_diag) {
                    max_below_secondary_diag = matrix[i][j];
                }
            }
            // Above the main diagonal
            if (j > i) {
                if (matrix[i][j] < min_above_main_diag) {
                    min_above_main_diag = matrix[i][j];
                }
            }
        }
    }

    cout << "Максимальный элемент ниже побочной диагонали: " << max_below_secondary_diag << endl;
    cout << "Минимальный элемент выше главной диагонали: " << min_above_main_diag << endl;

    // Free memory
    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
