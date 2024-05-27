#include <iostream>
#include <stack>
using namespace std;

// Given a string s consisting only of opening and closing parenthesis 
// 'ie '('  and ')', find out the length of the longest valid(well-formed) 
// parentheses substring.
// NOTE: The length of the smallest valid substring ( ) is 2.
// Example 1:
// Input: s = "(()("
// Output: 2
// Explanation: The longest valid 
// substring is "()". Length = 2.


//approach 1 using stack
 int findMaxLen(string s) 
    {
        // code here
        int maxi = 0;
        stack<int>st;
        st.push(-1);
        for(int i=0;i<s.length();i++)
        {
            char c = s[i];
            if(c == '(')
            {
                st.push(i);
            }
            else{
                 st.pop();
                if(!st.empty())
                {
                    maxi = max(maxi,i-st.top());
                   
                }
                else st.push(i);
            }
            
        }
        return maxi;
    }

    //approach 2 two pointers

    //  The first pass handles cases where the substring starts from the left, 
    //  and the second pass handles cases where the substring starts from the right.
 int findMaxLenI(string s) {
        int l = 0;
        int r = 0;
        int maxi = 0;
        for(int i = 0; i < s.size();i++){
            if(s[i]=='('){
                l++;
            }
            if(s[i]== ')'){
                r++;
            }
            
            if(l==r){
                maxi = max(maxi, 2*l);
            }
            if(l<r){
                l = 0;
                r = 0;
            }
        }
        //reinitialize
        l=0;
        r=0;
        for(int i = s.size()-1 ; i >= 0 ;i--){
            if(s[i]=='('){
                l++;
            }
            if(s[i]==')'){
                r++;
            }
            
            if(l==r){
                maxi = max(maxi, 2*l);
            }
            if(l>r){
                l = 0;
                r = 0;
            }
        }
        return maxi;
    }

int main()
{
    return 0;
}