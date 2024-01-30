#include<bits/stdc++.h>
using namespace std;


// Given two strings str1 and str2, and a third-string shuffle, 
//determine if shuffle is a valid shuffle of str1 and str2, 
//where a valid shuffle contains all characters from str1 and str2 
//occurring the same number of times, regardless of order. 
//Print “YES” if valid, and “NO” otherwise.
// Examples: 
// Input: str1 = BA, str2 = XY, shuffle = XYAB 
// Output: YES
// Input: str1 = BA, str2 = XY, shuffle = XUMB 
// Output: NO


//approach 1 strnew = str1+str2 /O(n+mlog(n+m))
//sort(strnew) sort(shuffle)
//return (strnew == shuffle)

//approach 2 using map//O(N)
bool validShuffle(string str1, string str2, string shuffle)
{
    // n1 = size of str1, n2 = size of str2
    int n1 = str1.size();
    int n2 = str2.size();
    // n = size of string shuffle
    int n = shuffle.size();

    // Its obvious if the no. of char in
    // shuffle are more or less than the
    // length of str1 and str2 then it
    // won't be a valid shuffle
    if (n != n1 + n2)
        return false;
 
    // We use an unordered map to keep
    // track of frequency of
    // each character.
    unordered_map<char, int> freq;//{If the code still works correctly with unordered_map<int, int>, 
    //it might be due to implicit conversions from char to int because characters can be represented as integers. 
    //However, it is better and more idiomatic to use char explicitly as the key type when dealing with characters.}
 
    // Count frequency of each char
    // in str1
    for (int i = 0; i < n1; i++)
        freq[str1[i]]++;
 
    // Count frequency of each char
    // in str2
    for (int i = 0; i < n2; i++)
        freq[str2[i]]++;
 
    // If any of the char is not found in
    // the map, then its not a
    // valid shuffle.
    for (int i = 0; i < n; i++) {
        if (freq.find(shuffle[i]) != freq.end())
            freq[shuffle[i]]--;
        else
            return false;
    }
    return true;
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
    string s1, s2,s3;
    cout << "Enter string1:" << endl;
    cin >> s1;
    cout << "Enter string2:" << endl;
    cin >> s2;
    cout<<"Enter shuffled string"<<endl;
    cin>>s3;
    print(s1);
    print(s2);
    print(s3);
    cout<<validShuffle(s1,s2,s3);
    return 0;
}