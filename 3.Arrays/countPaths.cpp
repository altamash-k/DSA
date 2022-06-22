#include<bits/stdc++.h>
using namespace std;


//Brute Force Recursive Approach:

// int countPaths(int i, int j, int n, int m)
// {
//     if(i == (n-1) && j == (m-1))
//         return 1;
//     else if(i >= n || j >= m)
//         return 0;
//     else
//         return countPaths(i+1, j, n, m) + countPaths(i, j+1, n, m);
// }

// Dynamic programming approach: 

// int countPaths(int i, int j, int n, int m, vector<vector<int>> &dp)
// {
//     if(i == (n-1) && j == (m-1))
//         return 1;
//     if(i >= n || j >= m)
//         return 0;
    
//     if(dp[i][j] != 0)
//         return dp[i][j];
//     else
//         return dp[i][j] = countPaths(i+1, j, n, m, dp) + countPaths(i, j+1, n, m, dp);
// }

// Using Combination Logic : n + m - 2
int countPaths(int n, int m)
{
    //for NCr
    int N = n + m - 2;
    int r = m - 1;
    double res = 1;

    for(int i = 1; i <= r; i++)
    {
        res = res * (N - r + i) / i;

        // Here N-r+i is for numerator and i for denominator
        // Eg: 10C3 = 8 * 9 * 10 / 1 * 2 * 3
        // therefore 8 * 9 * 10 is for res * (N - r + i)
        // and 1 * 2 * 3 is for i, as it is increasing one by one till r
    }

    return res;
} 

int main()
{
    vector<vector<int>> v;
    vector<vector<int>> dp;
    int n;
    cout << "Enter no of rows: ";
    cin >> n;
    int m;
    cout << "Enter no of cols: ";
    cin >> m;

    cout << "Total Possible paths are: ";
    cout << countPaths(n, m);
}