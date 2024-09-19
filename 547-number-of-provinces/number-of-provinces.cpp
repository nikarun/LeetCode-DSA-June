class Solution {
public:
    void dfs(int src, vector<vector<int>>&adj, vector<bool>&vis){
        if(vis[src]) return;
        vis[src]=true;
        for(int i=0;i<adj[src].size();++i){
            dfs(adj[src][i], adj, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj;
        for(int i=0;i<n;++i){
            vector<int>temp;
            for(int j=0;j<n;++j){
                if(isConnected[i][j]==1){
                    temp.push_back(j);
                }
            }
            adj.push_back(temp);
        }
        int count=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;++i){
            if(!vis[i]){
                ++count;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};