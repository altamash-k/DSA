#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> r(numRows);

    for(int i = 0; i < numRows; i++)
    {
        r[i].resize(i+1);
        r[i][0] = r[i][i] = 1;

        for(int j = 0; j < i; j++)
        {
            r[i][j] = r[i-1][j-1] + r[i-1][j];
        }
    }
    return r;
}

int main()
{
    vector<vector<int>> result = generate(5);
    for(int i= 0; i < result.size(); i++)
    {   
        for(int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}