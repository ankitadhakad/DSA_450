#include <iostream>
#include <string>
#include <vector>
using namespace std;

// approach 1 recursion//O(3^n)
int solve(string &s, int i, int j)
{
    if (i == j)
        return 1; // palindrome of length 1
    if (i > j)
        return 0;
    if (s[i] == s[j])
    {
        return 1 + solve(s, i + 1, j) + solve(s, i, j - 1);
    }
    else
        return solve(s, i + 1, j) + solve(s, i, j - 1) - solve(s, i + 1, j - 1);
}
// approach 2 memoization//O(N^2),O(N^2)
//to do -->tabulation /// using 2-D array instead of vector

int solveMemo(string &s, int i, int j, vector<vector<int>>&dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == j)
        return dp[i][j] = 1;
    int result;
    if (s[i] == s[j])
        result = 1 + solveMemo(s, i + 1, j, dp) + solveMemo(s, i, j - 1, dp);
    else
        result = solveMemo(s, i + 1, j, dp) + solveMemo(s, i, j - 1, dp) - solveMemo(s, i + 1, j - 1, dp);

    return dp[i][j] = result;
}

int main()
{
    string str = "abcb";
    int n = str.length();
   vector<vector<int>>dp(n,vector<int>(n,-1));
    cout << "Total palindromic subsequence are: " << solve(str, 0, str.length() - 1) << endl;
    cout << "Total palindromic subsequence are: " << solveMemo(str, 0, str.length() - 1, dp) << endl;
    return 0;
}
