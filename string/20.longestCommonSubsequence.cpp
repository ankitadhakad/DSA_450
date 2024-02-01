#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Given two strings, find the length of longest subsequence present in both of them.
// Both the strings are in uppercase latin alphabets.
// Example 1:
// Input:
// A = 6, B = 6
// str1 = ABCDGH
// str2 = AEDFHR
// Output: 3
// Explanation: LCS for input strings “ABCDGH” and “AEDFHR” is “ADH” of length 3.

// approach 1 recursion //O(2^n)
int lcs(string &s1, string &s2, int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    if (s1[i] == s2[j])
        return 1 + lcs(s1, s2, i - 1, j - 1);
    else
        return max(lcs(s1, s2, i - 1, j), lcs(s1, s2, i, j - 1));
}
// approach 2 memoization//O(N*M),O(N*M),stack space ->O(N+M)
int lcsmemo(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = 1 + lcsmemo(s1, s2, i - 1, j - 1, dp);
    else
        return dp[i][j] = max(lcsmemo(s1, s2, i - 1, j, dp), lcsmemo(s1, s2, i, j - 1, dp));
}

// approach 3 tabulation //O(N*M),O(N*M)
int lcstabu(string &s1, string &s2, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)

            {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main()
{
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    int n = s1.size();
    int m = s2.size();
    cout << lcs(s1, s2, n - 1, m - 1) << endl;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << lcsmemo(s1, s2, n - 1, m - 1, dp)<<endl;
    cout << lcstabu(s1, s2, n, m)<<endl;
    return 0;
}