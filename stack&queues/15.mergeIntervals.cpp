#include<iostream>
#include<stack>
#include<vector>
#include <algorithm>

using namespace std;

// Given an array of intervals where intervals[i] = [starti, endi], 
// merge all overlapping intervals, and return an array of the non-overlapping intervals 
// that cover all the intervals in the input.
// Example 1:
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// Example 2:
// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

class Solution {
public:
 static bool comparator(vector<int>&v1,vector<int>&v2)
 {
     return v1[0]<v2[0];
 }
    vector<vector<int>> mergeI(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comparator);
        stack<vector<int>>st;
        st.push(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            vector<int>temp=st.top();
            st.pop();
            if(temp[1]>=intervals[i][0])
            {
                int maxSecond=max(temp[1],intervals[i][1]);
                temp[1]=maxSecond;
                st.push(temp);
            }
            else{
                st.push(temp);
                st.push(intervals[i]);
            }
        }
        vector<vector<int>>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;

        
    }



    vector<vector<int>> mergeII(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comparator);
         vector<vector<int>> merged;
        for (auto interval : intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
}
};
int main()
{
    return 0;
}
