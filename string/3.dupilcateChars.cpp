#include <bits/stdc++.h>
using namespace std;


// Given a string S, 
//the task is to print all the duplicate characters with their occurrences in the given string.
// Example:
// Input: S = “geeksforgeeks”
// Output:
// e, count = 4
// g, count = 2
// k, count = 2
// s, count = 2

//approach 1 ocuurence of each element O(N^2)
void countI(string s)
{
    for(int i=0;i<s.size();i++)
    {
        int cnt = 1;
        char c = s[i];
        // if(c == '-1')
        // continue;
        for(int j=i+1;j<s.size();j++)
        {
            if( c == s[j])
            {
                cnt++;
                s[j] = '1';
            }
            
        }
        if(cnt > 1 && c!= '1')
            cout<<" "<<c<<", count = "<<cnt<<endl;
    }
}

void countII(string s)
{
    unordered_map<char,int>mp;
    for(int i=0;i<s.size();i++)
    {
        mp[s[i]]++;
    }
    for(auto it:mp)
    {
        if(it.second > 1)
        cout<<it.first<<", count = "<<it.second<<endl;
    }
}
void print(string s)
{
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i];
    }
}
int main()
{
    string s;
    cout<<"Enter string:"<<endl;
    cin>>s;
    print(s);
    cout<<endl;
    countI(s);
    cout<<endl;
    countII(s);
    return 0;
}