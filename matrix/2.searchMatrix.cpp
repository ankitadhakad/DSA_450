#include <bits/stdc++.h>
using namespace std;
// O(m*n)//brute force
bool search(vector<vector<int>> &matrix, int target)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}
// O(M+N)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int i = 0;
    int j = cols - 1;
    while (i < rows && j >= 0)
    {
        if (matrix[i][j] == target)
            return true;
        if (matrix[i][j] < target)
            i++;
        else
            j--;
    }
    return false;
}

// binary search O(log(m*n))

bool searchBinary(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int minRow = 0;
    int maxRow = m - 1;
    int midRow = (minRow + maxRow) / 2;
    while (minRow <= maxRow)
    {
        midRow = (minRow + maxRow) / 2;
        if (matrix[midRow][0] > target)
        {
            maxRow = midRow - 1;
        }
        else if (matrix[midRow][n - 1] < target)
        {
            minRow = midRow + 1;
        }
        else if (matrix[midRow][0] <= target && matrix[midRow][n - 1] > target)
        {
            maxRow = -1;
            minRow = midRow;
        }
    }
    if (matrix[midRow][0] > target || matrix[midRow][n - 1] < target)
        return false;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (matrix[midRow][mid] > target)
        {
            high = mid - 1;
        }
        else if (matrix[midRow][mid] < target)
        {
            low = mid + 1;
        }
        else
            return true;
    }
    return false;
}

void print(vector<vector<int>> &matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        cout << "[ ";
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << ", ";
        }
        cout << "]" << endl;
    }
}

int main()
{
    int m = 0;
    cout << "Enter rows:" << endl;
    cin >> m;
    int n = 0;
    cout << "Enter columns:" << endl;
    cin >> n;
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter elements of matrix" << endl;
            cin >> matrix[i][j];
        }
    }
    print(matrix, m, n);
    int target = -1;
    cout << "Enter target" << endl;
    cin >> target;
    cout << search(matrix, target) << endl;
    cout << searchMatrix(matrix, target) << endl;
    cout << searchBinary(matrix, target) << endl;
    return 0;
}