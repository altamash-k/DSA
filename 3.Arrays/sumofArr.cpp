#include <bits/stdc++.hm>
using namespace std;

int main() {
    int n1;
    cout << "Size of Array 1: " << endl;
    cin >> n1;
    
    int a1[n1];
    cout << "Enter Values of Array 1: " << endl;
    for (int i = 0; i < n1; i++) {
      cin >> a1[i];
    }

    int n2;
    cout << "Size of Array 2: " << endl;
    cin >> n2;

    int a2[n2];
    cout << "Enter Values of Array 2: " << endl;
    for (int i = 0; i < n2; i++) {
      cin >> a2[i];
    }

    int ans[n1 > n2? n1: n2];
    int len = sizeof(ans)/sizeof(ans[0]);
    int carry = 0;
    int i = n1 - 1;
    int j = n2 - 1;
    int k = len - 1;

    while (k >= 0)
    {               
        int sum = carry;
        if(i >= 0) {
            sum += a1[i];
        }
        if(j >= 0) {
            sum += a2[j];
        }

        int rem = sum % 10;
        int quot = sum / 10;
    
        ans[k] = rem;
        carry = quot;
        i--;
        j--;
        k--;
    }

    cout << "Final Ans: " << endl;
    if(carry != 0)
    {
        cout << carry << " ";
    }
    for (int i = 0; i < len; i++) {
        
        cout << ans[i] << " ";
    }

    return 0;
}