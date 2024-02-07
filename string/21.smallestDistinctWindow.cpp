#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Given a string 's'. The task is to find the smallest window length that contains
// all the characters of the given string at least one time.
// For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.
// Example 1:
// Input : "AABBBCBBAC"
// Output : 3
// Explanation : Sub-string -> "BAC"

// approach 1//O(N^3 in worst case)
int solve(string s, int n)
{
    int ans = n;
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        string temp = "";

        for (int j = i; j < n; j++)
        {
            temp += s[j];
            
            // bool flag = true;
            int count = 0;
            for (char c : temp)
            {
                if (mp.find(c) != mp.end())
                {
                    count++;
                }
             
            }
            if (count == mp.size())
            {
                ans = min(ans, j - i + 1);
            }
        }
    }
    return ans;
}

 int findSubString(string str)
    {
        unordered_map<char,int>mp;
        for(int i=0;i<str.length();i++)
        {
            mp[str[i]]++;
        }
        int i=0;
        int j=0;
        int s = mp.size();
        int ans = str.length();
        mp.clear();
        while(j<str.size())
        {
               mp[str[j]]++;
            
            
                while(mp.size() == s)
                {
                    ans = min(ans,j-i+1);
                    mp[str[i]]--;
                    if(mp[str[i]] == 0)
                    mp.erase(str[i]);
                    i++;
                }
            
            j++;
        }
        return ans;
    }
int main()
{
     string s = "aabcbcdbca";
     cout<<solve(s,s.length())<<endl;
     cout<<findSubString(s);
    return 0;
}