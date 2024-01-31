#include <bits/stdc++.h>
using namespace std;

// Given two strings s and t. Return the minimum number of operations required to convert s to t.
// The possible operations are permitted:
// Insert a character at any position of the string.
// Remove any character from the string.
// Replace any character from the string with any other character.
// Example 1:
// Input:
// s = "geek", t = "gesek"
// Output: 1
// Explanation: One operation is required
// inserting 's' between two 'e's of s.

// solution 1 recursion 3^n
int editDistance(string s, string t, int i, int j)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (s[i] == t[j])
    {
        return editDistance(s, t, i - 1, j - 1);
    }
    else
        return min(1 + editDistance(s, t, i, j - 1), min(1 + editDistance(s, t, i - 1, j), 1 + editDistance(s, t, i - 1, j - 1)));
}

// memoization approach//O(|s|*|t|)
int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (s1[i] == s2[j])

        dp[i][j] = solve(i - 1, j - 1, s1, s2, dp);

    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = 1 + min(solve(i - 1, j, s1, s2, dp), min(solve(i, j - 1, s1, s2, dp), solve(i - 1, j - 1, s1, s2, dp)));

    return dp[i][j];
}

// tabilation//space optimization//GFG solution
int editDistDP(string str1, string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int dp[m + 1][n + 1];

    // Fill d[][] in bottom up manner
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i == 0)
                dp[i][j] = j; // Min. operations = j

            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i

            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // If the last character is different, consider
            // all possibilities and find the minimum
            else
                dp[i][j] = 1 + min(dp[i][j - 1],           // Insert
                                   min(dp[i - 1][j],       // Remove
                                       dp[i - 1][j - 1])); // Replace
        }
    }

    return dp[m][n];
}

void print(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }
    cout << endl;
}
int main()
{
    string s1, s2;
    cout << "Enter string1:" << endl;
    cin >> s1;
    cout << "Enter string2:" << endl;
    cin >> s2;
    print(s1);
    print(s2);

    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << editDistance(s1, s2, m - 1, n - 1) << endl;
    cout << solve(m - 1, n - 1, s1, s2, dp);
    return 0;
}