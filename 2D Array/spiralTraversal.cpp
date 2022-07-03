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

    int minr = 0;
    int minc = 0;
    int maxr = row-1;
    int maxc = col-1;
    int total = row * col;
    int count = 0;
    
    cout << "Spiral traversal: " << endl;
    while(count < total)
    {

        // left wall
        for(int i = minr, j = minc; i <= maxr && count < total; i++)
        {
            cout << mat[i][j] << " ";
            count++;
        }
        minc++;

        // bottom wall
        for(int i = maxr, j = minc; j <= maxc && count < total; j++)
        {
            cout << mat[i][j] << " ";
            count++;
        }
        maxr--;
        // right wall
        for(int i = maxr, j = maxc; i >= minr && count < total; i--)
        {
            cout << mat[i][j] << " ";
            count++;
        }
        maxc--;
        //top wall
        for(int i = minr, j = maxc; j >= minc && count < total; j--)
        {
            cout << mat[i][j] << " ";
            count++;
        }
        minr++;
    }
}