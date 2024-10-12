class Solution {
public:
    bool isBipartiteBfs(int src, vector<vector<int>>& graph, vector<int>&colours, vector<bool>&vis){
        queue<int>q;
        q.push(src);
        colours[src]=0;
        while(!q.empty()){
            int top=q.front();
            vis[top]=true;
            q.pop();
            for(int i=0;i<graph[top].size();++i){
                int child_colour=colours[top]==0?1:0;
                if(colours[graph[top][i]]!=-1 && colours[graph[top][i]]!=child_colour) return false;
                colours[graph[top][i]] = child_colour;
                if(!vis[graph[top][i]]){
                    q.push(graph[top][i]);
                }

            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>colours(n,-1);
        vector<bool>vis(n,false);
        for(int i=0;i<n;++i){
            if(!vis[i]){
                if(!isBipartiteBfs(i,graph, colours, vis)) return false;
            }
        }
        return true;
    }
};