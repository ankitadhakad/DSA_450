#include <iostream>
#include <string>
#include <stack>
using namespace std;

// approach 1 brute force check foreach bracket if there exist matching bracket if no return false else return true;
// O(N^2)
bool ispar(string x) // failed ([)]//can't check correctly balanced paratheses
{
    int n = x.size();
    for (int i = 0; i < n; i++)
    {
        char ch = x[i];
        if (ch == '1')
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if ((ch == '(' && x[j] == ')') || (ch == '{' && x[j] == '}') || ch == '[' && x[j] == ']')
            {
                x[i] = '1';
                x[j] = '1';
                break;
            }
        }
        if (x[i] != '1')
            return false;
    }
    return true;
}
// tracking of number opening and closing bracket -->failed  case (}

// using stack
bool isValid(string s)
{
    stack<char> st;
    for (auto it : s)
    {
        if (it == '(' || it == '{' || it == '[')
            st.push(it);
        else
        {
            if (st.size() == 0)
                return false;
            char ch = st.top();
            st.pop();
            if ((it == ')' and ch == '(') or (it == ']' and ch == '[') or (it == '}' and ch == '{'))
                continue;
            else
                return false;
        }
    }
    return st.empty();
}
int main()
{
    string s = "()[{}()]";
    if (isValid(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}