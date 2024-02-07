#include <iostream>
#include <string>
using namespace std;
//approach 1 O(N^2)
class Solution
{

    bool ispalindrome(string s)
    {

        int l = s.length();
        int j;

        for (int i = 0, j = l - 1; i <= j; i++, j--)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

public:
    int minChar(string str)
    {

        int cnt = 0, l = str.size();

        while (l > 0)
        {

            if (ispalindrome(str.substr(0, l - cnt)))
            {
                break;
            }
            else
            {
                cnt++;
            }
        }

        return cnt;
    }
      int minCharII(string str){
     int n = str.length();
     int left = 0;
     int right = n-1;
     int added = 0;
     while(left < right)
     {
         if(str[left] == str[right])
         {
             left++;
             right--;
         }
        else {
               left = 0;
               added = n - right;
               while (str[left] == str[right]) {
                   added--;
                   left++;
               }
               right--;
           }
     }
     return added;
    
};
int main()
{

    return 0;
}