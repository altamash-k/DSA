#include <iostream>
using namespace std;

int merge(int arr[], int lb, int mid, int ub)
{
    mid = (lb + ub)/2;
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int res[100];
    while(i <= mid && j <= ub)
    {
        if(arr[i] <= arr[j])
        {
            res[k] = arr[i];
            i++;
        }
        else
        {
            res[k] = arr[j];
            j++;
        }
        k++;
        if(i > mid)
        {
            while(j <= ub)
            {
                res[k] = arr[j];
                j++;
                k++;
            }
        }
        else
        {
            while(i <= mid)
            {
                res[k] = arr[i];
                i++;
                k++;
            }
        }
        for(int k = lb; k < ub; k++)
        {
            arr[k] = res[k];
        }
    }
}

void mergesort(int arr[], int lb, int ub)
{
    if(lb < ub)
    {
        int mid = (lb + ub)/2;
        mergesort(arr, lb, mid);
        mergesort(arr, mid+1, ub);
        merge(arr, lb, mid, ub);
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

    mergesort(a, 0, n);

    cout << "Sorted Array is: " <<endl;
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    return 0;
}