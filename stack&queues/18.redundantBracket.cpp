#include <iostream>
#include <stack>
using namespace std;

// Given a string of balanced expressions, find if it contains a redundant parenthesis or not.
// A set of parenthesis is redundant if the same sub-expression is surrounded by 
//unnecessary or multiple brackets. Print ‘Yes‘ if redundant, else ‘No‘.
// Note: Expression may contain ‘+‘, ‘*‘, ‘–‘ and ‘/‘ operators. Given expression is valid 
// and there are no white spaces present.

// Examples: 

// Input: str = “((a+b))”
// Output: YES
// Explanation: ((a+b)) can reduced to (a+b), this Redundant


bool checkRedundancy(string& str)
{
    // create a stack of characters
    stack<char> st;
 
    // Iterate through the given expression
    for (auto& ch : str) {
 
        // if current character is close parenthesis ')'
        if (ch == ')') {
            char top = st.top();
            st.pop();
 
            // If immediate pop have open parenthesis '('
            // duplicate brackets found
            bool flag = true;
 
            while (!st.empty() and top != '(') {
 
                // Check for operators in expression
                if (top == '+' || top == '-' || 
                    top == '*' || top == '/')
                    flag = false;
 
                // Fetch top element of stack
                top = st.top();
                st.pop();
            }
 
            // If operators not found
            if (flag == true)
                return true;
        }
 
        else
            st.push(ch); // push open parenthesis '(',
                  // operators and operands to stack
    }
    return false;
}
 
// Function to check redundant brackets
void findRedundant(string& str)
{
    bool ans = checkRedundancy(str);
    if (ans == true)
        cout << "Yes\n";
    else
        cout << "No\n";
}
 

int main()
{
    string str = "((a+b))";
    findRedundant(str);
    return 0;
}