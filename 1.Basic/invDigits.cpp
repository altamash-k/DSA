#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, inv = 0;
    cout << "Enter the number: ";
    cin >> n;

    while(n>0)
    {
        inv = inv * 10 + n % 10;
        n = n/10;
    }
    cout << inv;
}