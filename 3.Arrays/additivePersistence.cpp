// Additive Persistence:
// num = 1645878
// 1+6+4+5+8+7+8 = 39
// 3+9 = 12
// 1+2 = 3
// Total Iterations are: 3


#include<bits/stdc++.h>
using namespace std;

int additivePersistence(int num)
{
    int b = 0;
    while(num > 0)
    {
        b += num%10;
        num = num /10;
    }
    return b;
}

int main()
{
    int num;
    cout << "Enter num: ";
    cin >> num;

    // cout << additivePersistence(num);

    int count = 0;
    while(num >= 10)
    {
        num = additivePersistence(num);
        count++;
    }

    cout << "Result will be: " << count;
}