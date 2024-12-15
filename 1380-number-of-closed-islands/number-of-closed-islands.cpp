class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid){
        if(i<0 || i==grid.size() || j<0 || j==grid[0].size()) return;
        if(grid[i][j]) return;
        grid[i][j]=1;
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        for(int p=0;p<4;++p){
                dfs(i+x[p], j+y[p],grid);
                }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if((i==0||j==0||i==m-1||j==n-1) && grid[i][j]==0){
                    dfs(i,j,grid);
                }
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==0 && !vis[i][j]){
                    dfs(i,j, grid);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};