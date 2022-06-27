#include<bits/stdc++.h>
using namespace std;

int maxPlatformReqd(int start[], int dep[], int n)
{
    sort(start, start + n);
    sort(dep, dep + n);
    int platform = 1;
    int max = 1;
    int i = 1, j = 0;

    while(i < n && j < n)
    {
        if(start[i] <= dep[j]) // if start time is lesser than dept time, increase platform
        {
            platform++;
            i++;
        }
        else if(start[i] > dep[j]) // if start time is greater than dept time, decrease platform
        {
            platform--;
            j++;
        }
        if(platform > max) // for finding maximum platform 
            max = platform;
    }

    return max;
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
        
    int dep[n];
    cout << "Enter dep Array: ";
    for(int i = 0; i < n; i++)
        cin >> dep[i];

    cout << "Max Platform Reqd will be: " << maxPlatformReqd(start, dep, n);
    return 0;
}