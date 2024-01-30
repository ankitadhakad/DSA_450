#include <bits/stdc++.h>
using namespace std;

// Given a string S, find the longest palindromic substring in S.
// Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S).
// Palindrome string: A string that reads the same backward.
// More formally, S is a palindrome if reverse(S) = S.
// In case of conflict, return the substring which occurs first ( with the least starting index).
// Example 1:
// Input:
// S = "aaaabbaa"
// Output: aabbaa
// Explanation: The longest Palindromic
// substring is "aabbaa".

// approach 1 //O(N^3)
// generate all substrings and for each string check if it is a palindrome
//  for(int i=0;i<n;i++)
//  {
//      string temp = "";
//      for(int j=i;j<n;j++)
//      {
//          temp+=s[j];
//          if(checkPalindrome(temp))
//          {
//              ans = max(ans,temp.length())
//              res = temp;
//          }
//      }
//  }

// approach 2 //O(n^2)//to do dp solution
string longestPalindrome(string s)
{
    int maxLength = -1;
    string ans = "";
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        // for odd
        int left = i;
        int right = i;
        while (left >= 0 && right < n && s[left] == s[right])
        {
            if (right - left + 1 > maxLength)
            {
                maxLength = right - left + 1;
                ans = s.substr(left, right - left + 1);
            }
            left--;
            right++;
        }
        // for even length palindrome
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right])
        {
            if (right - left + 1 > maxLength)
            {
                maxLength = right - left + 1;
                ans = s.substr(left, right - left + 1);
            }
            left--;
            right++;
        }
    }
    return ans;
}

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
    cout << longestPalindrome(s) << endl;
    return 0;
}