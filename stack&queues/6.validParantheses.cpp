#include<iostream>
#include <stack>
using namespace std;
// Given a string s containing just the characters 
// '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
// Example 1:
// Input: s = "()"
// Output: true
// Example 2:
// Input: s = "()[]{}"
// Output: true
bool check(char a,char b)
    {
        return ((a=='(' && b==')') || (a=='[' && b==']') || (a=='{'&& b=='}') );
    }
void isValid(string s)
{
    if(s.size()%2)
    {
         cout<<"false"<<endl;
         return;
    }
   
    stack<char>st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if(!st.empty() && !check(st.top(),s[i]))
        {
            cout<<"false"<<endl;
            return;
        }
        else if(!st.empty())
        st.pop();
        else {
            cout<<"false"<<endl;
            return;
        }

    }
    st.empty()?cout<<"true":cout<<"false";
    cout<<endl;
    
}
int main()
{
    string s = "{)}";
    isValid(s);
    return 0;
}