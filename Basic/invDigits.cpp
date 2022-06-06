#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, op, od, id, ip, inv = 0;
    cout << "Enter the number: ";
    cin >> n;

    op=1;
    while(n!=0)
    {
        od = n%10;
        id = op;
        ip = od;
        inv = inv + id * pow(10, ip-1);

        n = n/10;
        op++;

    }
    cout << inv;
}