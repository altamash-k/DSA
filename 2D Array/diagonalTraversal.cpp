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
    
    cout << "Diagonal Traversal: " << endl;
    for(int g = 0; g < row; g++)
    {
        for(int i = 0, j = g; j < col; i++, j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}