#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin >> n;
    int base1;
    cout << "Enter the number's Base value: ";
    cin >> base1;
    int base2;
    cout << "Enter the answer's Base value: ";
    cin >> base2;

    int ans = 0;
    int pow = 1;
    while(n > 0)
    {
        int dig = n % base2;
        n = n / base2;

        ans = ans + dig * pow;
        pow = pow * base1;
    }

    cout << "Answer: " << ans;
}