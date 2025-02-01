#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of data points (n): ";
    cin >> n;

    double x[100], y[100][100];

    cout << "Enter the values of x:\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter the values of y:\n";
    for (int i = 0; i < n; i++) {
        cin >> y[i][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }
    cout << "\nDivided Difference Table:\n";
    for (int i = 0; i < n; i++) {
        cout << x[i];
        for (int j = 0; j < n - i; j++) {
            cout << "\t" << y[i][j];
        }
        cout << endl;
    }

    double value = 8;
    double h = x[1] - x[0];
    double p = (value- x[0]) / h;

    double result = y[0][0];
    double term = 1;

    for (int i = 1; i < n; i++) {
        term *= (p - (i - 1)) / i;
        result += term * y[0][i];
    }

    cout << "\nThe interpolated value at x = " << value << " is " << result << endl;
    
    return 0;
}
