#include <bits/stdc++.h>
using namespace std;
 // ∫ 1/(1+x²) dx, upper = 1, lower = 0, interval = 6
   #define f(x) 1/(1+x*x)

/* ∫ x * e^(-0.5x) dx, upper = 6, lower = 0, interval = 3
    #define f(x) x*exp(-0.5*x)   */

/* ∫ √(1 + x³) dx, upper = 1, lower = 0, interval = 5
    #define f(x) sqrt(1+pow(x,3))   */

int main()
{
    double lower, upper, interval;
    cout << "Enter the lower and upper limit: " << endl;
    cin >> lower >> upper;
    cout << "Enter the value of interval" << endl;
    cin >> interval;

    double step = (upper - lower) / interval;
    double ans = f(lower) + f(upper);
    ans = ans / 2;
    for (double i = 1; i < interval; i++)
    {
        double x = lower + i * step;
        ans+= f(x);
    }
    cout << ans * step << endl;
}
