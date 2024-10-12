class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>&vis, int i,int j){
        if(i<0 || i==grid.size() || j<0 || j==grid[0].size()) return;
        if(vis[i][j]) return;
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        if(grid[i][j]=='1'){ 
            vis[i][j]=true;
            for(int p=0;p<4;++p){
                    dfs(grid,vis,i+x[p], j+y[p]);
                    }
        } 
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int count=0;
     
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ++count;
                    // vis[i][j]=1;
                    dfs(grid,vis,i,j);      
                }
            }
        }
        return count;
    }
};