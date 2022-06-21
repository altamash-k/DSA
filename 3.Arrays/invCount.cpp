// Count Inversion using Merge Sort

#include<bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int inv_count = 0;
    int i = left;
    int j = mid;
    int k = left;

    while((i <= mid-1) && (j <= right))
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid-i);
        }
    }

    while(i <= mid-1)
        temp[k++] = arr[i++];
    while(j <= right)
        temp[k++] = arr[j++];

    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return inv_count;
    
}

int merge_sort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if(right > left)
    {
        mid = (left + right) / 2;
        inv_count += merge_sort(arr, temp, left, mid);
        inv_count += merge_sort(arr, temp, mid+1, right);

        inv_count += merge(arr, temp, left, mid+1, right);
    }

    return inv_count;
}

int main()
{
    int n;
    cout << "Enter size of Arr: ";
    cin >> n;

    int arr[n];
    cout << "Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int temp[n];
    int ans = merge_sort(arr, temp, 0, n-1);
    cout << "Total inversions are: " << ans << endl;

    return 0;
}