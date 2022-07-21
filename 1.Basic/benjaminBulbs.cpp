#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of bulbs: ";
    cin >> n;

    cout << "Bulbs which are onn will be: ";
    for (int i = 0; i*i < n ; i++)
    {
        cout << i*i << " ";
    }
    
}