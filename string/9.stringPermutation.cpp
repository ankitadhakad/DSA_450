#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void permutation(string s, int index, int n) // O(N*N!)
    {
        if (index >= n)
        {
            cout << s << endl;
            return;
        }
        for (int i = index; i < n; i++)
        {
            swap(s[i], s[index]);
            permutation(s, index + 1, n);
            swap(s[i], s[index]);
        }
    }

    void permutationII(string s) // O(N*N!)
    {
        do
        {
            // keep adding while there is next permutation
            cout << s << endl;
        } while (next_permutation(s.begin(), s.end()));
        // If current string is lexicographically largest, such as “CBA”,
        // then next_permutation returns false
    }

    void permute(string s, string str) // O(N!)
    {
        if (s.length() == 0)
        {
            cout << str << endl;
            return;
        }
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            string left_substr = s.substr(0, i);
            string right_substr = s.substr(i + 1);
            string rest = left_substr + right_substr;
            permute(rest, str + ch);
        }
    }
};
void print(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }
}
int main()
{
    string s;
    cout << "Enter string:" << endl;
    cin >> s;
    int n = s.size();
    Solution ob;
    ob.permutation(s, 0, n);
    ob.permutationII(s);
    ob.permute(s, "");
    return 0;
}