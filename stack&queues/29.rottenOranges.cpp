#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
//optimized O(M*N)//brute force??
int orangesRotting(vector<vector<int>>& grid) 
    {
        
        int  n =grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    vis[i][j] = 2;
                    q.push({{i,j},0});
                }
            }
        }
        int ans = 0;
        int dr[4] = {0,1,0,-1};
        int dc[4] = {-1,0,1,0};
        while(!q.empty())
        {
            auto it = q.front();
            int currRow = it.first.first;
            int currCol = it.first.second;
            int t = it.second;
            q.pop();
            ans = max(ans,t);
            for(int i=0;i<4;i++)
            {
                int newRow = currRow+dr[i];
                int newCol = currCol +dc[i];
                if(newRow>=0 && newRow < n && newCol >=0 && newCol < m && grid[newRow][newCol] != 0 && vis[newRow][newCol]!=2)
                {
                    vis[newRow][newCol] = 2;
                    q.push({{newRow,newCol},t+1});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j] != 2 && grid[i][j] == 1)
                return -1;
            }
        }
        return ans;
    }
int main()
{
    return 0;
}