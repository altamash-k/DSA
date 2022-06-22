#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    double ans = 1.0;
    long long ncopy = n;
    if(ncopy < 0 )
    {
        ncopy = -1 * ncopy; // to make it positive
    }
    while(ncopy > 0 )
    {
        if(ncopy % 2 == 0)
        {
            ans = ans * x;
            ncopy = ncopy-1;
        }
        else
        {
            x = x * x;
            ncopy = ncopy / 2;
        }
    }
    if(n < 0)
    {
        ans = (double)(1.0)/(double) (ans);
    }
    return ans;
}

int main()
{
    double x;
    cout << "Enter x: " << endl;
    cin >> x;

    int n;
    cout << "Enter n: " << endl;
    cin >> n;

    cout << "Power of x ^ n is: ";
    cout << myPow(x, n) << endl;
}