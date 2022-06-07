#include<iostream>
using namespace std;

int main()
{
    int ans=0, n1, b, n2;

    cout<<"Enter number 1: ";
    cin>>n1;
    cout<<"Enter number 2: ";
    cin>>n2;
    cout<<"Enter Base Value: ";
    cin>>b;

    int pow = 1, c=0;
    while (n1>0 || c>0)
    {
        int dig1 = n1 % 10;
        // int dig2 = n2 % 10;
        n1 = n1 / 10;
        // n2 = n2 / 10;

        int d = dig1 * n2 + c;

        c = d / b;
        d = d % b;

        ans += d * pow;
        pow = pow * 10; 
    }z
    
    cout << ans;
}