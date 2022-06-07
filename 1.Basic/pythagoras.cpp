#include<iostream>
using namespace std;

int main()
{
    int a, b, c, max;
    bool flag;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    cout << "Enter third number: ";
    cin >> c;

    //find maximum
    if(a > b && a > c)
        max = a;
    else if(b>c)
        max = b;
    else
        max = c;
    
    //find triplet
    
    if(max == a)
    {
        flag = ((b*b + c*c)==(a*a));
        cout<<flag;
    }
    else if(max == b)
    {
        flag = ((a*a + c*c)==(b*b));
        cout<<flag;
    }
    else
    {
        flag = ((a*a + b*b)==(c*c));
        cout<<flag;
    }
}