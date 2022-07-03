#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row1, col1;
    cout << "Enter Row of Matrix 1: ";
    cin >> row1;

    cout << "Enter Col of Matrix 1: ";
    cin >> col1;
    
    int mat1[row1][col1];
    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < col1; j++)
        {
            cout << "\ns["<<i<<"]["<<j<<"]=  ";
            cin >> mat1[i][j];
        }
    }

    int row2, col2;
    cout << "Enter Row of Matrix 2: ";
    cin >> row2;

    cout << "Enter Col of Matrix 2: ";
    cin >> col2;
    
    int mat2[row2][col2];
    for(int i = 0; i < row2; i++)
    {
        for(int j = 0; j < col2; j++)
        {
            cout << "\ns["<<i<<"]["<<j<<"]=  ";
            cin >> mat2[i][j];
        }
    }

    cout << "Matrix 1: " << endl;
    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < col1; j++)
        {
            cout << mat1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Matrix 2: " << endl;
    for(int i = 0; i < row2; i++)
    {
        for(int j = 0; j < col2; j++)
        {
            cout << mat2[i][j] << " ";
        }
        cout << endl;
    }

    int mult[row1][col2];

    if(row2 != col1)
    {
        cout << "Invalid Operation";
        return -1;
    }
    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < col2; j++)
        {
            mult[i][j] = 0;
        }
    }

    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < col2; j++)
        {
            for(int k = 0; k < col1; k++)
            {
                mult[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    cout << "Prod Matrix: " << endl;
    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < col2; j++)
        {
            cout << mult[i][j] << " ";
        }
        cout << endl;
    }
}