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
    
    int dir = 0;
    int i = 0, j = 0;

    while(true)
    {
        dir = (dir + mat[i][j]) % 4;
        if(dir == 0)
            j++;
        else if(dir == 1)
            i++;
        else if(dir == 2)
            j--;
        else if(dir == 3)
            i--;


        if(i < 0)
        {
            i++;
            break;
        }
        else if(j < 0)
        {
            j++;
            break;
        }
        else if(i == row)
        {
            i--;
            break;
        }
        else if(j == col)
        {
            j--;
            break;
        }
    }

    cout << "Exit Point will be : [" << i << ", " << j << "]"; 
}