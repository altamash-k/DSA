#include<bits/stdc++.h>
using namespace std;

int candiesSum(vector<int> rating)
{
    int n = rating.size();
    vector<int> res(n); 
    fill(res.begin(), res.end(), 1); //initially all candies as 1 

    // forward direction
    for(int i = 1; i < n; i++)
    {
        if(rating[i] > rating[i-1]) // rating of next stud is greater than prev
        {
            res[i] = res[i-1] + 1; // next candie is prev candy + 1
        }
    }

    // backward direction
    for(int i = n-1; i > 0; i--)
    {
        if(rating[i] > rating[i+1] && res[i] <= res[i+1]) // rating of prev stud is lesser than next
        {
            res[i+1] = res[i] + 1;
        }
    }
    
    // to find min sum: 
    int sum = 0;
    for(int i = 0; i < res.size(); i++)
    {
        sum += res[i];
    }

    return sum;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int data;
    vector<int> arr;
    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        arr.push_back(data);
    }

    cout << "Sum of Min Candies Required are: " << candiesSum(arr);

    return 0;
}