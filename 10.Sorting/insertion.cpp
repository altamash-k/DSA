#include <iostream>
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
    
    int temp;
    for(int i = 1; i<n; i++)
    {
        temp = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j]>temp )
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

    cout << "Sorted Array is: " <<endl;
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    return 0;
}