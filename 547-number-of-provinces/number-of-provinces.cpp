class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<bool>&vis, int src){
        if(vis[src]) return;
        vis[src] = true;
        for(int i=0;i<adj[src].size();++i){
            dfs(adj,vis,adj[src][i]);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        if(n==0) return 0;
        vector<vector<int>>adj(n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool>vis(n,false);
        int count=0;
        for(int i=0;i<n;++i){
            if(!vis[i]){
                ++count;
                dfs(adj,vis,i);
            }
        }
        return count;
    }
};