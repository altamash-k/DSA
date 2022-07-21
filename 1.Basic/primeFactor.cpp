#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    
    int div;
    for(div=2; div*div <= n; div++)
    {
        while (n % div == 0)
        {
            n = n/10;
            cout<<div<<"\n";
        }
    }

    if(n!=1)
    {
        cout<<n<<"\n";
    }
}