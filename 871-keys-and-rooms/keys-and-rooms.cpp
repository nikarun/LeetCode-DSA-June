class Solution {
public:
    void dfs(int src, vector<bool>&vis, vector<vector<int>>& rooms){
        if(vis[src]) return;
        vis[src]=true;
        for(int i=0;i<rooms[src].size();++i){
            dfs(rooms[src][i],vis,rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        dfs(0,vis,rooms);
        for(int i=0;i<n;++i){
            if(vis[i]==false) return false;
        }
        return true;
    }
};