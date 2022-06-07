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
    
    for(int gap=n/2; gap>=1; gap = gap/2)
    {
        for(int j = gap; j < n; j++)
        {
            for(int i = j-gap; i>=0; i = i-gap)
            {
                if(arr[i+gap] > arr[i])
                    break;
                else
                {
                    int temp = arr[i];
                    arr[i] = arr[i+gap];
                    arr[i+gap] = temp;
                }
            }
        }
    }

    cout << "Sorted Array is: " <<endl;
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    return 0;
}