#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function to calculate the natural logarithm of the inverse quadratic function
double y(const double x) {
    return log(1 / (2 + 2 * x + x * x));
}

// Function to calculate the nth term of the alternating series for S(x)
double calculateNthTermOfSeries(const double x, const int i) {
    return pow(-1, i) * pow(1 + x, 2 * i) / i;
}

// Function to calculate the sum of the series S(x) up to the nth term
double calculateSumOfSeries(const double x, const int n) {
    double sum = 0.0;
    int currentTerm = 1;
    do {
        sum += calculateNthTermOfSeries(x, currentTerm);
        currentTerm++;
    } while (currentTerm <= n);
    return sum;
}

int main() {
    double a, b, h, currentValue, logarithmicValue, seriesSum;
    int n = 160;

    // Assign values to the lower and upper bounds
    a = -2;
    b = -0.1;

    // Calculate step size h
    h = (b - a) / 10;

    // Print the table header
    cout << setw(10) << "x" << setw(20) << "S(x)" << setw(20) << "Y(x)" << endl;

    // Calculate and print the values within the interval using a step size
    currentValue = a;
    do {
        seriesSum = calculateSumOfSeries(currentValue, n);
        logarithmicValue = y(currentValue);
        cout << setw(10) << currentValue << setw(20) << seriesSum << setw(20) << logarithmicValue << endl;
        currentValue += h;
    } while (currentValue <= b + h / 2);

    return 0;
}