#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Base number: ";
    cin >> n;
    int base;
    cout << "Enter Base value: ";
    cin >> base;

    int ans = 0;
    int pow = 1;
    while(n > 0)
    {
        int dig = n % 10;
        n = n / 10;

        ans = ans + dig * pow;
        pow = pow * base;
    }

    cout << "Answer: " << ans;
}