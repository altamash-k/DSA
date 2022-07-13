#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int largestArea(vector<int> &heights)
{
    int n = heights.size();

    int rb[n];
    stack<int> st;
    st.push(n-1);
    rb[n-1] = n;
    for(int i = n-2; i >=0; i--)
    {
        while(!st.empty() && heights[i] < heights[st.top()])
            st.pop();
        if(st.empty())
            rb[i] = n;
        else
            rb[i] = st.top();
        st.push(i);
    }

    int lb[n];
    st.push(0);
    lb[0] = -1;
    for(int i = 1; i < n; i++)
    {
        while(!st.empty() && heights[i] < heights[st.top()])
            st.pop();
        if(st.empty())
            lb[i] = -1;
        else
            lb[i] = st.top();
        st.push(i);
    }

    int maxArea = 0;
    for(int i = 0; i < n; i++)
    {
        int width = rb[i] - lb[i] - 1;
        int area = heights[i] * width;
        if(area > maxArea)
        {
            maxArea = area;
        }
    }

    return maxArea;
}

int main()
{
    int n;
    cout << "Enter no of elements: ";
    cin >> n;

    int data;
    vector<int> heights;
    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        heights.push_back(data);
    }

    cout << "Max Area: " << largestArea(heights);
}