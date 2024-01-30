#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void printSubsequences(string input, string output) // O(2^n)
    {
        if (input.empty())
        {
            cout << output << endl;
            return;
        }
        // take
        printSubsequences(input.substr(1), output + input[0]);
        // not take
        printSubsequences(input.substr(1), output);
    }
    void printSubSeqRec(string str, int n, int index = -1, string curr = "")//O(N*2^N)

    {
        // base case
        if (index == n)
            return;

        if (!curr.empty())
        {
            cout << curr << "\n";
        }

        for (int i = index + 1; i < n; i++)
        {

            curr += str[i];
            printSubSeqRec(str, n, i, curr);

            // backtracking
            curr = curr.erase(curr.size() - 1);
        }
        return;
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
    Solution ob;
    ob.printSubsequences(s, "");
    return 0;
}