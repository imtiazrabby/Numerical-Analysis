#include <bits/stdc++.h>
using namespace std;

#define f(x) 1/(1+x*x)

int main()
{
    double lower, upper, interval;
    cout << "Enter the lower and upper limit: " << endl;
    cin >> lower >> upper;
    cout << "Enter the value of interval" << endl;
    cin >> interval;

    double step = (upper - lower) / interval;
    double ans = f(lower) + f(upper);
    ans=ans;

    for (double i = 1; i < interval; i++)
    {
        double x = lower + i * step;
        if((int)i%2!=0 )ans +=4*f(x);
        else ans+= 2*f(x);
    }
    cout << ans *step/3 << endl;
}
