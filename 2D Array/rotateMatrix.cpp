#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix)
{
    for(int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    
}

int main()
{
    vector<vector<int>> arr;

    int r;
    cout << "Enter no of rows: ";
    cin >> r;
    int c;
    cout << "Enter no of cols: ";
    cin >> c;

    for(int i = 0; i < r; i++)
    {
        vector<int> rows;
        for(int j = 0; j < c; j++)
        {
            cout<<"\ns["<<i<<"]["<<j<<"]=  ";
            int value;
            cin >> value;
            rows.push_back(value);
        }
        arr.push_back(rows);
    }

    // arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Original Matrix is: \n";
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
            cout << "\t" << arr[i][j];
        cout<<endl;
    }

    rotate(arr);
    cout << "\nMatrix after Rotating 90 degrees: \n";
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
            cout << "\t" << arr[i][j];
        cout<<endl;
    }

    return 0;
}