/*
Enter n: 6
Enter Start Array: 900 945 955 1100 1500 1800
Enter dep Array: 920 1200 1130 1150 1900 2000
Max Platform Reqd will be: 3

Note: Here 0000 denotes 00:00
*/

#include<bits/stdc++.h>
using namespace std;

int maxPlatformReqd(int start[], int dep[], int n)
{
    // firstly sort both start and dept 
    sort(start, start + n);
    sort(dep, dep + n);

    // initially 1 platform will be there
    int platform = 1;
    int max = 1;

    // i will start from the second index 
    int i = 1, j = 0;

    while(i < n && j < n) // till reached to end
    {
        if(start[i] <= dep[j]) // if start time of train is lesser than dept time of prev train, increase platform
        {
            platform++; // as another platform will be reqd
            i++;
        }
        else if(start[i] > dep[j]) // if start time of train is greater than dept time, decrease platform
        {
            platform--; // as new platform will not be reqd for that train
            j++;
        }
        if(platform > max) // for finding maximum number of platforms reqd
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