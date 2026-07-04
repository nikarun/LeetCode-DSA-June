class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>vec(n+1);
        for(auto edge: roads){
            vec[edge[0]].push_back({edge[1],edge[2]});
            vec[edge[1]].push_back({edge[0],edge[2]});
        }

        int ans=INT_MAX;
        vector<bool>vis(n+1);
        queue<int>q;
        q.push(1);
        vis[1]=true;
        while(!q.empty()){
            auto node=q.front(); q.pop();

            for(auto &[v,dist]: vec[node]){
                ans=min(ans,dist);
                if(!vis[v]){
                    vis[v]=true;
     
                    q.push(v);
                }
            }
        }
        return ans;

    }
};