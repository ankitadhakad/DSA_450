#include <bits/stdc++.h>
using namespace std;


// Write a function that reverses a string. 
// The input string is given as an array of characters s.
// You must do this by modifying the input array in-place with O(1) extra memory.
// Example 1:
// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]


//O(n)
 void reverseString(vector<char>& s) 
    {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
        
    }
int main()
{
   vector<char>s = {'a','b','c'};
   reverseString(s);
   for(int i=0;i<s.size();i++)
   {
    cout<<s[i];
   }

    return 0;
}