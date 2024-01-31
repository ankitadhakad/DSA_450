#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

int count(string s) // O(N),O(N)
{
    int len = s.length();
    if (len % 2)
        return -1;
    int ans = 0;
    stack<char> st;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '{')
            st.push(s[i]);
        else
        {
            if (!st.empty())
                st.pop();
            else
            {
                st.push('{');
                ans++;
            }
        }
    }
    if (st.size() % 2)
        return -1;
    ans += st.size() / 2;
    return ans;
}
int countMinReversals(string s)//O(N),O(1)
{
    int len = s.length();
    int left = 0;
    int right = 0;
    int ans= 0;
     if (len % 2 != 0) {
        return -1;
    }
    for(int i=0;i<len;i++)
    {
        if(s[i] == '{')
        left++;
        else{
            if(left == 0)
            right++;
            else
            left--;
        }
    }
    ans = ceil(left / 2.0) + ceil(right/ 2.0);
    return ans;
}
int main()
{
    string expr = "}}{{";
    cout << count(expr)<<endl;
    cout<<countMinReversals(expr)<<endl;
    return 0;
}