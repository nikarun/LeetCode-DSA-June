class Solution {
public:
    int cnt;
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>>&vis){
        if(i<0 || i==grid.size() || j<0 || j==grid[0].size() || vis[i][j] || grid[i][j]==0) return;
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        vis[i][j]=true;
            ++cnt;
            for(int p=0;p<4;++p){
                    dfs(i+x[p], j+y[p],grid,vis);
                    }
                    // return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int maxArea=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1 && !vis[i][j]){
                    cnt=0;
                    dfs(i,j, grid,vis);
                    maxArea=max(maxArea, cnt);
                }
            }
        }
        return maxArea;
    }
};