// saddle point is a number which is min in its row, and max in its col
// there cant be more than one saddle point in the entire 2D arr

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
    
    // to find the smallest in the row

    for(int i = 0; i < row; i++)
    {
        int svj = 0;
        for(int j = 1; j < col; j++)
        {
            if(mat[i][j] < mat[i][svj])
                svj = j;
        }

        // to find the max in the col
        bool flag = true;

        for(int k = 0; k < row; k++)
        {
            if(mat[k][svj] > mat[i][svj])
            {
                flag = false;
                break;
            }
        }

        if(flag == true)
        {
            cout << "Saddle point is: " << mat[i][svj] << endl;
            break;
        }
    }
    
}