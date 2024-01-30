#include<bits/stdc++.h>
using namespace std;


// Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.
// The two identified subsequences A and B can use the same ith character from string str 
// if and only if that ith character has different indices in A and B. 
// For example, A = "xax" and B = "xax" 
// then the index of first "x" must be different in the original string for A and B.
// Example 1:
// Input:
// str = "axxzxy"
// Output: 2
// Explanation:
// The given array with indexes looks like
// a x x z x y 
// 0 1 2 3 4 5
// The longest subsequence is "xx". 
// It appears twice as explained below.
// subsequence A
// x x
// 0 1  <-- index of subsequence A
// ------
// 1 2  <-- index of str 
// subsequence B
// x x
// 0 1  <-- index of subsequence B
// ------
// 2 4  <-- index of str 
// We are able to use character 'x' 
// (at index 2 in str) in both subsequences
// as it appears on index 1 in subsequence A 
// and index 0 in subsequence B.

//longest common subsequence of two same strings
//to do -> space optimization
class Solution {
    


    int lcs(string X, string Y, int m, int n)//O(2^M*N) //recursive
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
        return max(lcs(X, Y, m, n - 1),
                   lcs(X, Y, m - 1, n));
}


    int solve(string &s1,string &s2,vector<vector<int>>&dp,int i,int j)//dp(m*n)
    {
        if(i>=s1.length() || j>=s2.length())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        return dp[i][j];
        else{
            if(s1[i]==s2[j] && i!=j)
            dp[i][j] = 1+solve(s1,s2,dp,i+1,j+1);
            else
            dp[i][j] = max(solve(s1,s2,dp,i+1,j),solve(s1,s2,dp,i,j+1));
        }
        return dp[i][j];
    }
	public:
		int LongestRepeatingSubsequence(string str)
		{
		    // Code here
		    int n = str.length();
		    vector<vector<int>>dp(n,vector<int>(n,-1));
		    string copy(str.begin(),str.end());
		    return solve(str,copy,dp,0,0);
		}

};
void print(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }
}
int main()
{
    string s;
    cout << "Enter string:" << endl;
    cin >> s;
   Solution ob;
   cout<<ob.LongestRepeatingSubsequence(s);
    return 0;
}