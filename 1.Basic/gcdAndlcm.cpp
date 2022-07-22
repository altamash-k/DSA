#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2;
    cout<<"Enter first number: ";
    cin>>n1;
    cout<<"Enter second number: ";
    cin>>n2;

    int on1 = n1;
    int on2 = n2;
    int rem;

    while(n1 % n2 != 0)
    {
        rem = n1 % n2;
        n1 = n2;
        n2 = rem;
    }
    int gcd = n2;
    cout << "GCD of the numbers are: " << gcd << "\n";

    int lcm = (on1*on2)/gcd;
    cout << "LCM of the numbers are: " << lcm;
}