#include <bits/stdc++.h>
using namespace std;
// Given a row wise sorted matrix of size R*C 
//where R and C are always odd, find the median of the matrix.
// Example 1:
// Input:
// R = 3, C = 3
// M = [[1, 3, 5], 
//      [2, 6, 9], 
//      [3, 6, 9]]
// Output: 5
// Explanation: Sorting matrix elements gives 
// us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 


//approach 1 store them in vector and then find out median O(n*m)

//approach 2 O(R*logC)
int smallerElements(vector<int>&row,int middle)
{
    int low = 0;
    int high = row.size()-1;
    while(low <= high)
    {
        int mid = low+(high-low)/2;
        if(row[mid] <= middle)
        low = mid+1;
        else
        high = mid-1;
    }
    return low;
}

int median(vector<vector<int>>&matrix,int R,int C)
{
    int low = 0;
    int high = INT_MAX;
     while(low<=high)
     {
        int mid = low+(high-low)/2;
        int count = 0;//sounting smaller elements than mid
        for(int i=0;i<R;i++)
        {
            count+=smallerElements(matrix[i],mid);
        }
        if(count<=(R*C)/2)
        low = mid+1;
        else high = mid-1;

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

    cout<<median(matrix,m,n)<<endl;
}