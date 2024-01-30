#include <bits/stdc++.h>
using namespace std;

// approach 1 reverse and check if both the strings are same or not

// approach 2 two pinters

int isPalindrome(string &s)
{
    int i = 0;
    int j = s.size() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
int main()
{
    string s;
    cout << "Enter string" << endl;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }
    cout<<endl;
    cout<<isPalindrome(s);



    return 0;
}