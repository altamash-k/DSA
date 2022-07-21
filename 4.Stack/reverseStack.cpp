#include<bits/stdc++.hm>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int el)
{
    if(st.empty())
    {
        st.push(el);
        return;
    }
    int topel = st.top();
    st.pop();
    insertAtBottom(st, el);

    st.push(topel);
}

void reverse(stack<int> &st) {

    if(st.empty())
    {
        return;
    }
    int el = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, el);
}

int main()
{

    stack<int> st1;
    stack<int> st2;
    int n;
    cout << "Enter no of elements: ";
    cin>> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        st1.push(arr[i]);
    }

    int ch;
	while(1)
	{
		
        cout<<"\nChoose the operations:\n1: Reverse Stack Recursively\n2: Reverse Stack using 2 stacks"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                reverse(st1);
                while(!st1.empty())
                {
                    cout << st1.top() << " ";
                    st1.pop();
                }
                break;
            case 2:
                while(!st1.empty())
                {
                    st2.push(st1.top());
                    st1.pop();
                    int ans = st2.top();
                    st2.pop();
                    // cout << "Stack Reverse using 2 stacks: " << endl;
                    cout << ans << " ";
                }
                break;
            
        }		
	}

}