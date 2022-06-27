#include<bits/stdc++.h>
using namespace std;

void fun(int ind, int sum, vector<int>& arr, int n, vector<int>& sumSubset)
{
    if(ind == n)
    {
        sumSubset.push_back(sum);
        return;
    }

    fun(ind + 1, sum +  arr[ind], arr, n, sumSubset);

    fun(ind + 1, sum, arr, n, sumSubset);

}

vector<int> subSetSum(vector<int> arr, int n)
{
    vector<int> sumSubset;
    fun(0, 0, arr, n, sumSubset);
    sort(sumSubset.begin(), sumSubset.end());
    return sumSubset;
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

    vector<int> sumSubset;
    sumSubset = subSetSum(arr, n);
    cout << "Subset Sum are: ";
    for(auto it : sumSubset)
        cout << it << " ";
}