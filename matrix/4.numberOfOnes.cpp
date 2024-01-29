#include <bits/stdc++.h>
using namespace std;

// Given a boolean 2D array of n x m dimensions, consisting of only 1's and 0's, 
//where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.
// Example 1:
// Input: 
// N = 4 , M = 4
// Arr[][] = {{0, 1, 1, 1},
//            {0, 0, 1, 1},
//            {1, 1, 1, 1},
//            {0, 0, 0, 0}}
// Output: 2
// Explanation: Row 2 contains 4 1's (0-based
// indexing).


//approach 1 count one in each row and find maximum O(M*N)


//approach 2 O(M+N)
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) 
	{
	   int ans = -1;
	   int row = 0;
	   int col = m-1;
	   while(row<n && col>=0)
	   {
	       if(arr[row][col] == 1)
	       {
	           ans = row;
	           col--;
	       }
	       else{
	           row++;
	       }
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

    cout<<rowWithMax1s(matrix,m,n);
    return 0; 
}