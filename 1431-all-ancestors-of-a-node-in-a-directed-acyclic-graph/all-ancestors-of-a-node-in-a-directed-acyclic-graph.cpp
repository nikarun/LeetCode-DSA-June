class Solution {
public:
    void dfs(vector<vector<int>>&graph,int parent, int src, vector<vector<int>>&ans){
        for(int it:graph[src]){
            if(ans[it].empty() || ans[it].back()!=parent){
                ans[it].push_back(parent);
                dfs(graph,parent,it,ans);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>graph(n);
        vector<vector<int>>ans(n);
        for(int i=0;i<edges.size();++i){
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        // vector<bool>vis(n,false);
        for(int i=0;i<n;++i){
                dfs(graph,i,i,ans);
        }
        return ans;
}
};