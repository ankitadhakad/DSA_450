#include<bits/stdc++.h>
using namespace std;

// Given a string s of lowercase alphabets and a number k, 
// the task is to print the minimum value of the string after removal of k characters.
//  The value of a string is defined as the sum of squares of the count of each 
//  distinct character present in the string. 
//  Example 1:

// Input: 
// s = abccc, k = 1
// Output: 
// 6
// Explaination:
// We remove c to get the value as 1^2 + 1^2 + 2^2
 int minValue(string s, int k){
        // code here
        int sum=0;
        unordered_map<char,int>mp;
        priority_queue<int>pq;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        for(auto i:mp)
        {
            pq.push(i.second);
        }
        for(int i=0;i<k;i++)
        {
            int top=pq.top();
            pq.pop();
            pq.push(top-1);
            
        }
        while(!pq.empty())
        {
            int top=pq.top();
            pq.pop();
            sum+=top*top;
        }
        return sum;
    }
int main()
{
    return 0;
}