#include <bits/stdc++.h>
using namespace std;

// r = 4, c = 4
//  matrix[][] = {{1, 2, 3, 4},
//             {5, 6, 7, 8},
//             {9, 10, 11, 12},
//             {13, 14, 15,16}}
//  Output:
//  1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

vector<int> spiral(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> ans;
    int Srow = 0;
    int Scol = 0;
    int Erow = m - 1;
    int Ecol = n - 1;
    // int size = m*n;
    while (Srow <= Erow && Scol <= Ecol)
    {
        for (int i = Scol; i <= Ecol && Srow <= Erow; i++)
        {
            ans.push_back(matrix[Srow][i]);
            // size--;
        }
        Srow++;
        for (int i = Srow; i <= Erow && Scol <= Ecol; i++)
        {
            ans.push_back(matrix[i][Ecol]);
            // size--;
        }
        Ecol--;
        for (int i = Ecol; i >= Scol && Srow <= Erow; i--)
        {
            ans.push_back(matrix[Erow][i]);
            // size--;
        }
        Erow--;
        for (int i = Erow; i >= Srow && Scol <= Ecol; i--)
        {
            ans.push_back(matrix[i][Scol]);
            // size--;
        }
        Scol++;
    }
    return ans;
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

    vector<int> v = spiral(matrix);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}