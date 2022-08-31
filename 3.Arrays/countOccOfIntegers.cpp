#include<bits/stdc++.h>
using namespace std;

void countOccur(vector<int>& arr)
{
    sort(arr.begin(), arr.end());
    int count = 1;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == arr[i+1])
        {
            count ++;
        }
        else
        {
            cout << arr[i] << " occurs " << count << " times\n";
            count = 1;
        }
    }
}

int main()
{
    vector<int> arr;
    int n;
    cout << "Enter n: ";
    cin >> n;

    int data;
    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        arr.push_back(data);
    }

    countOccur(arr);
}