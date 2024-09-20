class Solution {
public:
    void calculate_ans(vector<int>adj[], vector<bool>&vis, int &ans, int src){
        vis[src] = true;
        for(auto &v:adj[src]){
            if(!vis[abs(v)]){
                if(v>0){
                    ++ans;
                }
                calculate_ans(adj, vis, ans, abs(v));
            }
        }
    }
    void make_adj(vector<int> adj[], vector<vector<int>>& connections){
        for(int i=0;i<connections.size();++i){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(-connections[i][0]);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        make_adj(adj, connections);
        int ans=0;
        vector<bool>vis(n, false);
        calculate_ans(adj, vis, ans, 0);
        return ans;
    }
};