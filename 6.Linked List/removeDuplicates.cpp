#include<bits/stdc++.h>
using namespace std;

list<int> ques, ans;

void removeDuplicates()
{
    
    while(ques.size() > 0)
    {
        int val = ques.front();
        ques.pop_front();
        ans.push_back(val);

        if(ans.size() == 0 || ans.back() != val)
        {
            ans.push_back(val);
        }
    }
    ques.front() = ans.front();
    ques.back() = ans.back();
    ques.size() = ans.size();
}

int main()
{
    ques.push_back(2);
    ques.push_back(2);
    ques.push_back(2);
    ques.push_back(3);
    ques.push_back(3);
    ques.push_back(4);
    ques.push_back(4);
    ques.push_back(4);
    ques.push_back(4);
    ques.push_back(4);
    ques.push_back(5);
    ques.push_back(5);
    ques.push_back(5);
    while (!ques.empty())
    {
        cout << ques.front() << " ";
        ques.pop_front();
    }

    removeDuplicates();

    while (!ques.empty())
    {
        cout << ques.front() << " ";
        ques.pop_front();
    }
    
}