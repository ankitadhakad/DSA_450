#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;


// Given a string S with repeated characters. 
// The task is to rearrange characters in a string such that no two adjacent characters are the same.
// Note: The string has only lowercase English alphabets and it can have multiple solutions. 
// Return any one of them.
// Example 1:
// Input : str = "geeksforgeeks"
// Output: 1
// Explanation: All the repeated characters of the
// given string can be rearranged so that no 
// adjacent characters in the string is equal.
// Any correct rearrangement will show a output
// of 1.

//approach 2 O(N+KlogK)
string rearrangeString(string str)
    {
       
        int n = str.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[str[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        string ans = "";
        while(pq.size() > 1)
        {
            pair<int,int>p1 = pq.top();
            pq.pop();
            
            pair<int,int>p2 = pq.top();
            pq.pop();
            
            p1.first--;
            p2.first--;
            
            ans += p1.second;
            ans += p2.second;
            
            if(p1.first)
            pq.push(p1);
            
            if(p2.first)
            pq.push(p2);
        }
        if(pq.size())
        {
            if(pq.top().first==1)
            {
                ans += pq.top().second;
            }
            else
            return "-1";
        }
        return ans;
    }
    
    //approach 2 //O(N)
    string rearrange(string str)
    {
        vector<int>charCounts(26,0);
        for(char c:str)
        {
            charCounts[c-'a']++;
        }
        int maxCount = 0;
        int letter = 0;
        for(int i=0;i<charCounts.size();i++)
        {
            if(charCounts[i] > maxCount)
            {
                maxCount = charCounts[i];
                letter = i;
            }
        }
        if(maxCount > (str.length()+1)/2)
        return "-1";
        vector<char>ans(str.length(),0);
        int index = 0;
        while(charCounts[letter] !=0)
        {
            ans[index] = char(letter+'a');
            index+=2;
            charCounts[letter]--;
        }
        for(int i=0;i<charCounts.size();i++)
        {
            while(charCounts[i] > 0)
            {
                if(index>=str.size())
                {
                    index = 1;
                }
                ans[index] = char(i+'a');
                index+=2;
                charCounts[i]--;
            }
        }
        return string(ans.begin(),ans.end());

    }

int main()
{
    string s = "geeksforgeeks";
     string res = rearrangeString(s);
     cout<<res<<endl;
     string res2 = rearrange(s);
     cout<<res2;
    return 0;
}