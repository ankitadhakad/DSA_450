#include <iostream>
#include <stack>
using namespace std;
// Given string S representing a postfix expression, 
// the task is to evaluate the expression and find the final value. 
// Operators will only include the basic arithmetic operators like *, /, + and -.
// Example 1:
// Input: S = "231*+9-"
// Output: -4
// Explanation:
// After solving the given expression, 
// we have -4 as result.
int evaluatePostfix(string S)
    {
        // Your code here
         stack<int> st;
        for(auto it:S)
        {
            if(it=='+' || it=='-' || it=='*' || it=='/')
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                
                if(it=='+')
                {
                    st.push(b+a);
                }
                else if(it=='-')
                {
                    st.push(b-a);
                }
                else if(it=='*')
                {
                    st.push(b*a);
                }
                else{
                    st.push(b/a);
                }
            }
            else{
                st.push(it-'0');
            }
        }
        
        return st.top();
    }

int main()
{
    cout<<evaluatePostfix("231*+9-");
    return 0;
}