#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
// {
//     Given an array of intervals where intervals[i] = [starti, endi], 
//     merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
// Example 1:
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// }


//approach 1 brute force
//A simple approach is to start from the first interval 
//and compare it with all other intervals for overlapping, 
//if it overlaps with any other interval, then remove the other 
//interval from the list and merge the other into the first interval.
// Repeat the same steps for the remaining intervals after the first. 
//This approach cannot be implemented in better than O(n^2) time.

//approach 2 using stack
vector<vector<int>>mergeIntervals(vector<vector<int>>&intervals)
{
    if (intervals.empty()) {
        return vector<vector<int>>();
    }
 
    // Sort intervals based on start values
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    stack<vector<int>>mergedStack;
    mergedStack.push(intervals[0]);
    for(int i=1;i<intervals.size();i++)
    {
        vector<int>curr = intervals[i];
        vector<int>&top = mergedStack.top();
        if(curr[0] <= top[1])
        {
            top[1] =max(top[1],curr[1]);
        }
        else
        {
            mergedStack.push(curr);
        }
    }
    vector<vector<int>>ans;
    while(!mergedStack.empty())
    {
        ans.push_back(mergedStack.top());
        mergedStack.pop();
    }
    return ans;

}

//approach 3 space optimization
 vector<vector<int>>merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
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
int main()
{
    int n=0;
    cout<<"Enter the size of intervals"<<endl;
    cin>>n;
    vector<vector<int>>intervals(n);
    for(int i=0;i<n;i++)
    {
        int x,y;
       cout<<"Enter start point of interval"<<endl;
       cin>>x;
       intervals[i].push_back(x);
        cout<<"Enter end point of interval"<<endl;
       cin>>y;
       intervals[i].push_back(y);
    }
    for(int i=0;i<n;i++)
    {
         cout<<"["<<intervals[i][0]<<" "<<intervals[i][1]<<"] ";
    }


    cout<<endl;
    vector<vector<int>>ans = mergeIntervals(intervals);

sort(ans.begin(), ans.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    for(int i=0;i<ans.size();i++)
    {
         cout<<"["<<ans[i][0]<<" "<<ans[i][1]<<"] ";
    }
    return 0;
}