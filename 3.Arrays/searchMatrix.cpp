#include<bits/stdc++.h>
using namespace std;

bool searchInMatrix(vector<vector<int>>& matrix, int target)
{
    //using binary searh technique
    
    int low = 0;
    if(matrix.size() == 0)
        return 0;
    int high = matrix.size()-1;

    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] == target)
            return true;
        if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
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

    int target;
    cout << "Enter target: ";
    cin >> target;

    // arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    cout << "Original Matrix is: \n";
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
            cout << "\t" << arr[i][j];
        cout<<endl;
    }

    if(searchInMatrix(arr, target) == true)
        cout << "Element found";
    else
        cout << "Element not found";

}