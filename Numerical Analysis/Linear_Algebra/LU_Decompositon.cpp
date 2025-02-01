#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

void luDecomposition(int mat[][MAX], int n)
{
    int lower[n][n], upper[n][n];
    memset(lower, 0, sizeof(lower));
    memset(upper, 0, sizeof(upper));

     for (int i = 0; i < n; i++)
    {
        // Lower
        for (int j = 0; j < n; j++)
            cout << setw(6) << lower[i][j] << "\t";
        cout << "\t";

        // Upper
        for (int j = 0; j < n; j++)
            cout << setw(6) << upper[i][j] << "\t";
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        // Upper Triangular
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = 0; k < i; k++)
                sum += (lower[i][k] * upper[k][j]);

            upper[i][j] = mat[i][j] - sum;
        }

        // Lower Triangular
        for (int j = i; j < n; j++)
        {
            if (i == j)
                lower[i][i] = 1; // Diagonal as 1
            else
            {
                // Summation of L(j, k) * U(k, i)
                int sum = 0;
                for (int k = 0; k < i; k++)
                    sum += (lower[j][k] * upper[k][i]);

                lower[j][i] = (mat[j][i] - sum) / upper[i][i];
            }
        }
    }

    cout << setw(6) << "      Lower Triangular" << setw(32) << "Upper Triangular" << endl;

    for (int i = 0; i < n; i++)
    {
        // Lower
        for (int j = 0; j < n; j++)
            cout << setw(6) << lower[i][j] << "\t";
        cout << "\t";

        // Upper
        for (int j = 0; j < n; j++)
            cout << setw(6) << upper[i][j] << "\t";
        cout << endl;
    }
}

int main()
{
    int mat[][MAX]
        = { { 2, -1, -2 }, { -4, 6, 3 }, { -4, -2, 8 } };

    luDecomposition(mat, 3);
    return 0;
}
