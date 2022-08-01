// multiplicative Persistence:
// num = 77
// 7 * 7 = 49
// 4 * 9 = 36
// 3 * 6 = 18
// 1 * 8 = 8
// Total Iterations are: 4


#include<bits/stdc++.h>
using namespace std;

int multiplicativePersistence(int num)
{
    int b = 1;
    while(num > 0)
    {
        b *= num%10;
        num = num /10;
    }
    return b;
}

int main()
{
    int num;
    cout << "Enter num: ";
    cin >> num;

    // cout << multiplicativePersistence(num);

    int count = 0;
    while(num >= 10)
    {
        num = multiplicativePersistence(num);
        count++;
    }

    cout << "Result will be: " << count;
}