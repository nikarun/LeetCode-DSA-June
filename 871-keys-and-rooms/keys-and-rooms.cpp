class Solution {
public:
    void dfs(int src, vector<bool>&vis,vector<vector<int>>& adj){
        if(vis[src]) return;
        vis[src]=true;
        for(int i=0;i<adj[src].size();++i){
            dfs(adj[src][i],vis,adj);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        int no=0;
        for(int i=0;i<n;++i){
            if(!vis[i]){
                dfs(i,vis,rooms);
                ++no;
            }
        }

        return no<=1;
    }
};