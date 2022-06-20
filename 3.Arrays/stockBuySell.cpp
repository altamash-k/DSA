#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> v)
{
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for (int i = 0; i < v.size(); i++)
    {
        minPrice = min(v[i], minPrice); // to find min elem in array
        maxProfit = max(maxProfit, v[i] - minPrice); 
    }
    return maxProfit;
} 

int main()
{
    int n;
    cout << "Enter no of values: ";
    cin >> n;

    int data;
    vector<int> v;
    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        v.push_back(data);
    }

    cout << "Maximum Profit will be: ";
    cout << maxProfit(v);
}