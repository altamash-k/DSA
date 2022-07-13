/*
    Given array of temps, return an array w/ # of days until warmer
    Ex. temperature = [73,74,75,71,69,72,76,73] -> [1,1,4,2,1,1,0,0]

    Monotonic decr stack, at each day, compare incr from prev days

    Time: O(n)
    Space: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperature(vector<int>& temperatuure)
{
    int n = temperatuure.size();
    stack<pair<int, int>> st;

    vector<int> res(n);

    for(int i = 0; i < n; i++)
    {
        int currDay = i;
        int currTemp = temperatuure[i];

        while(!st.empty() && st.top().second < currTemp)
        {
            int prevDay = st.top().first;
            int prevTemp = st.top().second;
            st.pop();

            res[prevDay] = currDay-prevDay; 
        }

        st.push({currDay, currTemp});
    }

    return res;
}

int main()
{
    int n;
    cout << "Enter no of elements: ";
    cin >> n;

    int data;
    vector<int> temperatuure;
    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        temperatuure.push_back(data);
    }

    vector<int> res = dailyTemperature(temperatuure);

    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

}