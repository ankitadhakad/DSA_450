#include <bits/stdc++.h>
using namespace std;

// Given a string s1 and a string s2,
// write a function to check whether s2 is a rotation of s1.
// Examples:
// Input: S1 = ABCD, S2 = CDAB
// Output: Strings are rotations of each other
// Input: S1 = ABCD, S2 = ACBD
// Output: Strings are not rotations of each other

bool checkI(string s1, string s2) // O(N^2) in worst case
{
    int n1 = s1.size();
    int n2 = s2.size();
    if (n1 != n2)
        return false;
    for (int i = 0; i < n1; i++)
    {
        if (s2[i] == s1[0])
        {    bool flag = true; // found first character
        for (int j = 0; j < n2; j++)
        {
            if (s1[j] != s2[(i + j) % n1])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return true;
        }
    }
    return false;
}
bool checkII(string s1, string s2) // O(N^2)
{
    int n1 = s1.size();
    int n2 = s2.size();
    if (n1 != n2)
        return false;
    queue<char> q1;
    for (int i = 0; i < n1; i++)
    {
        q1.push(s1[i]);
    }
     queue<char> q2;
    for (int i = 0; i < n2; i++)
    {
        q2.push(s2[i]);
    }
    while (n1--)
    {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q1 == q2)
            return true;
    }
    return false;
}
bool checkIII(string s1, string s2) // O(N)//to do --> use of (kmp algo)
{
    if (s1.length() != s2.length())
        return false;

    string temp = s1 + s1;
    return (temp.find(s2) != string::npos);
}

void print(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }
    cout << endl;
}
int main()
{
    string s1, s2;
    cout << "Enter string1:" << endl;
    cin >> s1;
    cout << "Enter string2:" << endl;
    cin >> s2;
    print(s1);
    print(s2);
    cout << checkI(s1, s2) << endl;
    cout << checkII(s1, s2) << endl;
    cout << checkIII(s1, s2) << endl;
    return 0;
}