#include<bits/stdc++.hm>
using namespace std;

int main()
{
    int ans, n1, b, n2;

    cout<<"Enter number 1: ";
    cin>>n1;
    cout<<"Enter number 2: ";
    cin>>n2;
    cout<<"Enter Base Value: ";
    cin>>b;

    int pow = 1, c=0;
    while (n1>0 || n2>0 || c>0)
    {
        int dig1 = n1 % 10;
        int dig2 = n2 % 10;
        n1 = n1 / 10;
        n2 = n2 / 10;

        int d = dig1 + dig2 + c;

        c = d / b;
        d = d % b;

        ans += d * pow;
        pow = pow * 10; 
    }
    
    cout << ans;
}