#include <iostream>
using namespace std;

int main() 
{
    int n, i;
    cout << "Enter value of n: ";
    cin >> n;

    int a = 0, b = 1l;
    for(i = 0; i < n; i++)
    {
        int c;
        cout << a << " ";
        c = a+b;
        a = b;
        b = c;
    }
}