#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> dummy1(rows, -1), dummy2(cols, -1);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(matrix[i][j] == 0)
            {
                dummy1[i] = 0;
                dummy2[j] = 0;
            }
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(dummy1[i] == 0 || dummy2[j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
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

    // arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    cout << "Original Matrix is: \n";
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
            cout << "\t" << arr[i][j];
        cout<<endl;
    }

    setZeroes(arr);
    cout << "\nMatrix after Setting Zeroes: \n";
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
            cout << "\t" << arr[i][j];
        cout<<endl;
    }


}