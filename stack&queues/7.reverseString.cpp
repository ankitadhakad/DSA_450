#include <iostream>
#include  <stack>
using namespace std;
// You are given a string S, the task is to reverse the string using stack.
// Example 1:
// Input: S="GeeksforGeeks"
// Output: skeeGrofskeeG
void reverse(string s)
{
    stack<char>st;
    for(int i=0;i<s.size();i++)
    {
        st.push(s[i]);
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
}
int main()
{    string s="hello";
cout<<s<<endl;
reverse(s);
    return 0;
}