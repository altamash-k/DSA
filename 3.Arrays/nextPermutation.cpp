/* 
Enter no of elements: 5
Enter values: 1 3 5 4 2
Next Permutation will be: 1 4 2 3 5 
*/

#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& v)
{
    int n = v.size(), k, l;
    for(k = n-2; k >= 0; k--)
    {
        if(v[k] < v[k+1])
            break;
    }
    if(k < 0)
        reverse(v.begin(), v.end());
    else
    {
        for(l = n-1; l > k; l--)
        {
            if(v[l] > v[k])
                break;
        }
        swap(v[l], v[k]);
        reverse(v.begin() + k + 1, v.end());
    }
}

int main()
{
    int n;
    cout << "Enter no of elements: ";
    cin >> n;

    int data;
    vector<int> v;
    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        v.push_back(data);
    }
    
    cout << "Next Permutation will be: ";

    nextPermutation(v);
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}