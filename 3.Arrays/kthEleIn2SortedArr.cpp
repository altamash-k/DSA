#include<bits/stdc++.h>
using namespace std;

void kth(int arr1[], int arr2[], int n1, int n2, int k)
{
    vector<int>ans;
    int temp1 = 0;
    int temp2 = 0;
    int maxn = max(n1, n2);
    for(int i = 0; i < maxn; i++)
    {
        if(arr1[temp1] > arr2[temp2])
        {
            ans.push_back(arr2[temp2]);
            temp2++;
        }
        if(arr2[temp2] > arr1[temp1])
        {
            ans.push_back(arr1[temp1]);
            temp1++;
        }
    }
    for(int i = temp1; i < n1; i++)
        ans.push_back(arr1[i]);
    for(int i = temp2; i < n2; i++)
        ans.push_back(arr2[i]);

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    cout << "Kth element is: " << ans[k-1];
}

int main()
{
    int arr1[5] = {2, 3, 6, 7, 9};
    int arr2[4] = {1, 4, 8, 10};
    int k = 5;
    kth(arr1, arr2, 5, 4, k);
    return 0;
}