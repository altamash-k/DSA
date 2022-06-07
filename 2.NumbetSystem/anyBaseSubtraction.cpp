#include<iostream>
using namespace std;

int main()
{
    int ans = 0, n1, n2, b;
    cout<<"Enter Number 1: ";
    cin>>n1;
    cout<<"Ente Number 2: ";
    cin>>n2;
    cout<<"Enter Base Value: ";
    cin>>b;

    int pow = 1, borr = 0;
    
    while(n2>0)
    {
        int dig1 = n1%10;
        int dig2 = n2%10;
        n1 = n1/10;
        n2 = n2/10;

        int dig=0;
        dig1 = dig1 + borr;
        if(dig1 < dig2)
        {
            borr = -1;
            dig = dig1+b-dig2;
        }
        else
        {
            borr = 0;
            dig = dig1-dig2;
        }

        ans = ans + dig * pow;
        pow = pow * 10;
    }

    cout << ans;
}