class Solution {
public:
    int dfs(int i,int j, vector<vector<int>>& matrix, vector<vector<int>>&dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int x[] = {-1,0,1,0};
        int y[] = {0,1,0,-1};
        int res=0;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int k=0;k<4;++k){
            if(x[k]+i>=0 && x[k]+i<m && y[k]+j>=0 && y[k]+j<n && matrix[x[k]+i][y[k]+j]>matrix[i][j]){
                res=max(res,1+dfs(x[k]+i,y[k]+j,matrix,dp));
            }
        }
        return dp[i][j]=res;
    
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int res=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        //do dfs from every point 
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                res=max(res,dfs(i,j,matrix,dp));
            }
        }
        return res+1;
    }
};