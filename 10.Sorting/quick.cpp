#include <bits/stdc++.hm>
using namespace std;

int partition(int arr[], int lb, int ub)
{
    int start, end, pivot = arr[lb], t;
    start = lb;
    end = ub;
    while(start < end)
    {
        while(arr[start] <= pivot)
        {
            start++;
        }
        while(arr[end] > pivot)
        {
            end--;
        }
        if(start < end)
        {
            t = arr[start];
            arr[start] = arr[end];
            arr[end] = t;
        }
    }
    t = arr[lb];
	arr[lb] = arr[end];
	arr[end] = t;

    return end;
}

void quicksort(int arr[], int lb, int ub)
{
    if(lb<ub)
    {
        int loc = partition(arr, lb, ub);
        quicksort(arr, lb, loc-1);
        quicksort(arr, loc+1, ub);
    }
}

int main() {

    int a[100], n;
    cout << "Size of Array: " << endl;
    cin >> n;  
    cout << "Enter Values of Array: " << endl;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    quicksort(a, 0, n-1);

    cout << "Sorted Array is: " <<endl;
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    return 0;
}