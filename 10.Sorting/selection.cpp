#include <bits/stdc++.hm>
using namespace std;

int main() {
    int n;
    cout << "Size of Array: " << endl;
    cin >> n;
    
    int arr[n];
    cout << "Enter Values of Array: " << endl;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    
    for(int i = 0; i<n-1; i++)
    {
        int min = i;
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    cout << "Sorted Array is: " <<endl;
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    return 0;
}