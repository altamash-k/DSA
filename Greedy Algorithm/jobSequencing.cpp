#include<bits/stdc++.h>
using namespace std;

// A Job has an ID, deadline, and profit
struct Job{
    int id;
    int deadline;
    int profit;
};

bool comparator(Job a, Job b)
{
    // to return the max profit between two jobs
    return (a.profit > b.profit);
}

pair<int, int> JobScheduling(Job arr[], int n)
{
    // first sort the arr with desending order of profits
    sort(arr, arr+n, comparator);

    // initially maximum will be starting value ka deadline
    int maxi = arr[0].deadline;
    for(int i = 1; i < n; i++)
    {
        // now will find the actual maximum deadline
        maxi = max(maxi, arr[i].deadline);
    }

    // make an arr named slot of the maximum deadline size
    int slot[maxi + 1];

    // initialize all values of slot as -1
    for(int i = 0; i < n; i++)
    {
        slot[i] = -1;
    }

    // firstly no of jobs and its profit will be 0
    int countJobs = 0, jobProfit = 0;


    for(int i = 0; i < n; i++) // from start to end
    {
        for(int j = arr[i].deadline; j > 0; j--) // from deadline value of i
        {
            if(slot[j] == -1) // if at the deadline value we find -1
            {
                slot[i] = i; // we will store the job index at that slot position
                countJobs++; // as a job is done, so we have to increase it
                jobProfit += arr[i].profit; // also profit from that job is updated accordingly
                break;
            }
            /* if it is not possible to enter the job index at its slot value, 
            then as loop is decrementing we can fll it in other slots */
        }
    }

    // finally return the pair of no of jobs and profit
    return make_pair(countJobs, jobProfit);
}

int main()
{
    int n = 4;
    Job arr[n] = {{1, 4, 20}, {2, 1, 10}, {3, 2, 40}, {4, 2, 30}};

    pair<int, int> ans = JobScheduling(arr, n);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}