#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cout << "Enter Row of Matrix: ";
    cin >> row;

    cout << "Enter Col of Matrix: ";
    cin >> col;
    
    int mat[row][col];
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << "\ns["<<i<<"]["<<j<<"]=  ";
            cin >> mat[i][j];
        }
    }

    cout << "Matrix: " << endl;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "Wave traversal: " << endl;
    for(int j = 0; j < col; j++) // cols are increasing always
    {
        if(j % 2 == 0)// if cols are even, rows increase
        {
            for(int i = 0; i < row; i++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        else // if cols are odd rows decreasey
        {
            for(int i = row-1; i >= 0; i--)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
}