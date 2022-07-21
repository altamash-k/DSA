#include<bits/stdc++.hm>
using namespace std;

int main()
{
    int n, k;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Enter the rotator position: ";
    cin >> k; 

    int temp = n;
    int div = 1, mult = 1;
    int nod = 0;
    while(temp > 0)
    {
        temp = temp/10;
        nod++;
    }

    k = k%10;
    if(k<0)
    {
        k = k+nod;
    }

    int i;
    for(i = 1; i<=nod; i++)
    {
        if(i<=k)
        {
            div = div*10;
        }
        else
        {
            mult = mult * 10;
        } 
    }

    int q = n / div;
    int rem = n % div;

    int rot = rem * mult + q;
    cout << rot;
}