#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x[20], y[20][20], i, j, n;
    cout << "Enter the number of data points:" << endl;
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "x[" << i << "]: ";
        cin >> x[i];
        cout << "y[" << i << "]: ";
        cin >> y[i][0];
    }

    for (i = 1; i < n; i++)
    {
        for (j = i; j < n - i; j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j - 1][i - 1];
        }
    }

    cout << "Central Difference Table:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = " << x[i];
        for (j = 0; j < n - i; j++)
        {
            cout << "\t" << y[i][j];
        }
        cout << endl;
    }

    return 0;
}
