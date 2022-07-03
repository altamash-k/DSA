#include<bits/stdc++.h>
using namespace std;

void spiralAnti(vector<vector<int>>& mat, int row, int col)
{
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
void spiralClock(vector<vector<int>>& mat, int row, int col)
{
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
        for(int i = minr, j = minc; j <= maxc && count < total; j++)
        {
            cout << mat[i][j] << " ";
            count++;
        }
        minr++;

        // bottom wall
        for(int i = minr, j = maxc; i <= maxr && count < total; i++)
        {
            cout << mat[i][j] << " ";
            count++;
        }
        maxc--;
        // right wall
        for(int i = maxr, j = maxc; j >= minc && count < total; j--)
        {
            cout << mat[i][j] << " ";
            count++;
        }
        maxr--;
        //top wall
        for(int i = maxr, j = minc; i >= minr && count < total; i--)
        {
            cout << mat[i][j] << " ";
            count++;
        }
        minc++;
    }
}

int main()
{
    int row, col;
    cout << "Enter Row of Matrix: ";
    cin >> row;

    cout << "Enter Col of Matrix: ";
    cin >> col;
    

    vector<vector<int>> mat;
    for(int i = 0; i < row; i++)
    {
        vector<int> rows;
        for(int j = 0; j < col; j++)
        {
            cout<<"\ns["<<i<<"]["<<j<<"]=  ";
            int value;
            cin >> value;
            rows.push_back(value);
        }
        mat.push_back(rows);
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

    cout << "Choose Operation:\n1: Spiral Clockwise \n2: Spiral Anticlockwise\n";
    int ch;
    cout << "Enter choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
        spiralClock(mat, row, col);
        break;
    case 2:
        spiralAnti(mat, row, col);
        break;
    default:
        break;
    }
    
}