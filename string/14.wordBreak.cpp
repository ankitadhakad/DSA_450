
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;


// Given a string A and a dictionary of n words B, find out 
// if A can be segmented into a space-separated sequence of dictionary words.
// Note: From the dictionary B each word can be taken any number of times and in any order.
// Example 1:
// Input:
// n = 6
// B = { "i", "like", "sam", "sung", "samsung", "mobile"}
// A = "ilike"
// Output:
// 1
// Explanation:
// The string can be segmented as "i like".

 //O(2^n) solution to do --> dp solution
// Function to check if the given word can be broken
// down into words from the wordList
bool WordBreak(const vector<string>& wordList,
               const string& word)
{
    // If the word is empty, it can be broken down into
    // an empty list of words
    if (word.empty())
        return true;
 
    int wordLen = word.length();
 
    // Check if the word can be broken down into
    // words from the wordList
    for (int i = 1; i <= wordLen; ++i) {
        string prefix = word.substr(0, i);
 
        if (find(wordList.begin(), wordList.end(), prefix)
                != wordList.end()
            && WordBreak(wordList, word.substr(i))) {
            return true;
        }
    }
 
    return false;
}
 
int main()
{
    vector<string> wordList
        = { "mobile", "samsung",  "sam",  "sung", "man",
            "mango",  "icecream", "and",  "go",   "i",
            "like",   "ice",      "cream" };
 
    bool result = WordBreak(wordList, "ilikesamsung");
 
    cout << boolalpha << result << endl; // Output: true
 
    return 0;
}