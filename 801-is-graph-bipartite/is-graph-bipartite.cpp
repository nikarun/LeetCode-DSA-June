class Solution {
public:
    bool isGraphBipartite(int src, int colour, vector<bool>&vis, vector<int>&colours,vector<vector<int>>& graph){
        if(vis[src]){
            return colours[src]==colour;
        }
        colours[src]=colour;
        vis[src]=true;
        int child_colour=colour==0?1:0;
        for(int i=0;i<graph[src].size();++i){
            if(!isGraphBipartite(graph[src][i],child_colour,vis,colours,graph)){
                return false;
            }
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>is_visited(n,false);
        vector<int>colour(n,-1);
        for(int i=0;i<n;++i){
            if(!is_visited[i]){
                if(!isGraphBipartite(i,0,is_visited,colour,graph)) return false;
            } 
        }
        return true;
    }
};