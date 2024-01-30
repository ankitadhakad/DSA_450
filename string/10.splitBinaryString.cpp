#include <bits/stdc++.h>
using namespace std;

// Given binary string str of length N.
// The task is to find the maximum count of consecutive substrings str
// can be divided into such that all the substrings are balanced
// i.e. they have an equal number of 0s and 1s.
// If it is not possible to split str satisfying the conditions then return -1.
// Example 1:
// Input:
// S = "0100110101"
// Output: 4
// Explanation:
// The required substrings are 01, 0011, 01 and 01.

int maxSubStr(string str)//O(N)
{

    int ans = 0;
    int count = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
            count++;

        else
            count--;

        if (!count)
            ans++;
    }
    if (count)
        return -1;
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
    cout << maxSubStr(s) << endl;
    return 0;
}