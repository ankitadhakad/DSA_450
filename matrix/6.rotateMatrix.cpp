#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>> &matrix, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            // swapping elements at (i,j) and (j,i).
            swap(matrix[i][j], matrix[j][i]);
}

// after transposing we swap elements of each column (1st with last, 2nd with
// second last) one by one for finding left rotation of matrix by 90 degree.
void reverseColumns(vector<vector<int>> &matrix, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0, k = n - 1; j < k; j++, k--)
            // swapping elements in each column.
            swap(matrix[j][i], matrix[k][i]);
}

// Function to rotate matrix anticlockwise by 90 degrees.
void rotateby90(vector<vector<int>> &matrix, int n)
{
    transpose(matrix, n);
    reverseColumns(matrix, n);
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
    rotateby90(matrix, n);
    print(matrix, m, n);

    return 0;
}