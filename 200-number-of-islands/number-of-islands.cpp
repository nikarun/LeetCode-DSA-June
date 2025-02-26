class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>&vis){
        if(vis[i][j]) return;
        vis[i][j]=true;
        vector<int> x={-1,1,0,0};
        vector<int> y={0,0,-1,1};
        int m=grid.size();
        int n=grid[0].size();
        for(int k=0;k<4;++k){
            if(x[k]+i>=0 && x[k]+i<m && y[k]+j>=0 && y[k]+j<n && grid[x[k]+i][y[k]+j]=='1'){
                dfs(grid,x[k]+i,y[k]+j,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==0||n==0) return 0;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int islands=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(grid,i,j,vis);
                    ++islands;
                }
            }
        }
        return islands;
    }
};