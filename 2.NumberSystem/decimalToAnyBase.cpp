#include<bits/stdc++.hm>
using namespace std;

int main()
{
    int n;
    cout<<"Enter decimal value: ";
    cin >> n;
    int base;
    cout << "Enter Any Base value: ";
    cin >> base;

    int ans = 0;
    int pow = 1;
    while(n > 0)
    {
        int dig = n % base;
        n = n / base;

        ans = ans + dig * pow;
        pow = pow * 10;
    }

    cout << "Answer: " << ans;
}