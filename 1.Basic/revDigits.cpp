#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, rem;
    cout << "Enter the number: ";
    cin >> n;

    while(n!=0)
    {
        rem = n % 10;
        n = n/10;
        cout << rem;
    }
}