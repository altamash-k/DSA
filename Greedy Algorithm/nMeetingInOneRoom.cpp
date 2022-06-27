/*
Enter n: 6
Enter Start Array: 1 3 0 5 8 5
Enter end Array:   2 4 5 7 9 9
Order of meetings will be: 
1 2 4 5
*/

#include<bits/stdc++.h>
using namespace std;

struct meeting {
    int start;
    int end;
    int pos;
};

bool comprator(struct meeting m1, meeting m2)
{
    //for comparing the end values of meeting
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.pos < m2.pos) return true;
    return false;
}

void maxMeetings(int s[], int e[], int n)
{
    struct meeting meet[n];
    for(int i = 0; i < n; i++) // storing all start, end, pos values in meet arr
    {
        meet[i].start = s[i];
        meet[i].end = e[i];
        meet[i].pos = i+1;
    }

    sort(meet, meet + n, comprator); // sort meeting acc to end value

    vector<int> answer;

    int limit = meet[0].end; // initial limit will be frst end position
    answer.push_back(meet[0].pos); // first meeting will always be held

    for(int i = 1; i < n; i++) // starting from the second index
    {
        if(meet[i].start > limit) // if the start of next meeting is higher than prev limit
        {
            limit = meet[i].end; // update the limit
            answer.push_back(meet[i].pos); // store the meetings position
        }

        // else do nothing
        // now ans arr has all the meetings that can be attended
    }

    cout << "Order of meetings will be: " << endl;
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int start[n];
    cout << "Enter Start Array: ";
    for(int i = 0; i < n; i++)
        cin >> start[i];
        
    int end[n];
    cout << "Enter end Array: ";
    for(int i = 0; i < n; i++)
        cin >> end[i];

    maxMeetings(start, end, n);

    return 0;
}