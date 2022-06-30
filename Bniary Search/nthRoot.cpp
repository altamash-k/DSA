#include<bits/stdc++.h>
using namespace std;

double multiply(double number, int n)
{
    double ans = 1.0;
    for(int i = 1; i <= n; i++)
    {
        ans = ans*number;
    }
    return ans;
}

double getNthRoot(int n, int m)
{
    double low = 1;
    double high = m;
    double abs = 1e-6;

    while((high - low) > abs)
    {
        double mid = (high + low) / 2;
        if(multiply(mid, n) < m)
            low = mid;
        else
            high = mid;
    }

    cout << low;
}

int main()
{
    int n, m;
    cout << "Ente n: ";
    cin >> n;
    cout << "Enter m; ";
    cin >> m;

    getNthRoot(n, m);
    return 0;
}