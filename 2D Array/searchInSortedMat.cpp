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
    
    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int i = 0;
    int j = col-1;

    int flag = false;
    while(i < row && j >=0)
    {
        int mid = mat[i][j];
        if(target == mid)
        {
            flag = true;
            break;
        }
        else if(target < mid)
            j--;
        else if(target > mid)
            i++;
    }
    if(flag == true)
        cout << "Element found at: [" << i << ", " << j << "]" ;
    else
        cout << "Element not found" << endl;

}