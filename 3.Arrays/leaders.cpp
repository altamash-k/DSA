// input : {16, 17, 4, 3, 5, 2}
// output : 17, 5, 2
// explanation: 17 and 5 becoz they are greater than prev ele, and the last element will always be leader

#include<bits/stdc++.h>
using namespace std;
  
void printLeaders(int arr[], int size)
{
    stack<int> st;
    st.push(arr[size - 1]);

    int max_right = arr[size-1];
    for(int i = size-2; i >= 0; i--)
    {
        if(arr[i] > max_right)
        {
            max_right = arr[i];
            st.push(max_right);
        }
    }  

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
  
int main()
{
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printLeaders(arr, n);
    return 0;
}