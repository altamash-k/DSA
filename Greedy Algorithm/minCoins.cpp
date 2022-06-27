/*
Enter the value of coin: 49
Minimum coins will be / Change will be: 5
Coins are: 20 20 5 2 2
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    
    int v;
    cout << "Enter the value of coin: ";
    cin >> v; 

    vector<int>ans;

    for(int i = 8; i >= 0; i--) // start from end of coins arr
    {
        while(v >= coins[i]) // till value >= coins arr value
        {
            v -= coins[i]; // decrement value by that coin value
            ans.push_back(coins[i]); // add the coin value to ans array
        }
    }

    cout << "Minimum coins will be / Change will be: " << ans.size() << endl;
    cout << "Coins are: ";
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}