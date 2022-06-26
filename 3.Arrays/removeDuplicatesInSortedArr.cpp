// input: 1 1 1 2 2 3 3 3 3
// output: 1 2 3

#include<bits/stdc++.h>
using namespace std;

void removeDuplicatesInSortedArr(vector<int> arr)
{
    int n = arr.size();
    int i = 0;
    for(int j = 1; j < n; j++)
    {
        if(arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    cout << "After Removal of Duplicates: ";
    for(int k = 0; k < i+1; k++)
    {
        cout << arr[k] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int data;
    vector<int> arr;
    cout << "Enter data: ";
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        arr.push_back(data);
    }

    removeDuplicatesInSortedArr(arr);

    return 0;
}