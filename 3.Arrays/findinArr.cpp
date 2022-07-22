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

    int key;
    cout << "Enter Key: " << endl;
    cin >> key;
    int pos = -1;

    for (int i = 0; i < n; i++) {
      if(arr[i] == key) {
          pos = i;
          break;
      }
    }

    if(pos < 0) {
        cout << "Element not Found";
    } else {
        cout << "Element found at " << pos << " position" << endl; 
    }
    
    return 0;
}