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
    for(int i = 0; i < n-1; i++)
    {
        int flag = 0;
        for(int j = 0; j<n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
        break;
    }

    cout << "Sorted Array is: " <<endl;
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    return 0;
}