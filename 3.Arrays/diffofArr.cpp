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
    // cout<<sizeof(ans);
    int len = sizeof(ans)/sizeof(ans[0]);
    int borrow = 0;
    int i = n1 - 1;
    int j = n2 - 1;
    int k = len - 1;

    while (k >= 0)
    {               
        int diff = a1[i] - borrow;
        if(j >= 0) {
            diff -= a2[j];
        }
        if(diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        ans[k] = diff;
        i--;
        j--;
        k--;

    }

    cout << "Final Ans: " << endl;
    i = 0;
    while(ans[i] == 0) {
        i++;
    }
    while(i < len) {
        cout << ans[i] << " ";
        i++;
    }

    return 0;
}