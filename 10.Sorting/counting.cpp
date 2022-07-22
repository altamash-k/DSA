#include <bits/stdc++.h>
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
    
    for(int i = 1;i < n; ++i) {
        if(arr[0] < arr[i])
        arr[0] = arr[i];
    }

    int k = arr[0];
    int count[k+1];
    int res[n];

    for(int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    for(int i = 1; i <= k; i++)
    {
        count[i] = count[i] + count[i-1];
    }
    for(int i = n-1; i >= 0; i--)
    {
        res[--count[arr[i]]] = arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        arr[i] = res[i];
    }

    cout << "Sorted Array is: " <<endl;
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    return 0;
}