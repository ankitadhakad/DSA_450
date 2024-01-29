#include <bits/stdc++.h>
using namespace std;

// Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

// Example 1:
// Input:
// N = 4
// mat[][] =          {{16, 28, 60, 64},
//                    {22, 41, 63, 91},
//                    {27, 50, 87, 93},
//                    {36, 78, 87, 94 }}
// K = 3
// Output: 27
// Explanation: 27 is the 3rd smallest element.

// approach 1 convert this into a vector
// sort the vector and find out kth smallest elements O(N*N)

// approach 2 heap  O(N*KlogN)//to do --> using (buid heap heapify)
int kth(vector<vector<int>> mat, int n, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pq.push(mat[i][j]);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }
    return pq.top();
}

// approach 3 binary search O(N*log(max-min))
int smallerThanMid(vector<int> arr, int middle, int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= middle)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int kthSmallest(vector<vector<int>> mat, int n, int k)
{
    int low = 0;
    int high = 10000;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += smallerThanMid(mat[i], mid, n); // upper bound can be used here
        }
        if (count < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
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
    int n = 0;
    cout << "Enter size:" << endl;
    cin >> n;
    int k = 0;
    cout << "Enter k" << endl;
    cin >> k;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter elements of matrix" << endl;
            cin >> matrix[i][j];
        }
    }
    print(matrix, n, n);
    cout << kthSmallest(matrix, n, k) << endl;
    cout << kth(matrix, n, k) << endl;
    return 0;
}
