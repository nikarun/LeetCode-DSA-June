class Solution {
public:
    int maxInformTime=0;
    int itr=0;
    void dfs(int root, vector<int>& informTime, vector<vector<int>> &adj, int time){
        ++itr;
        cout<<itr<<endl;
        if(adj[root].size()==0) maxInformTime=max(maxInformTime, time);
        for(int i=0;i<adj[root].size();++i){
            dfs(adj[root][i],informTime,adj, time+informTime[root]);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        vector<vector<int>> adj(n);
        for(int i = 0; i < manager.size();++i){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        dfs(headID,informTime,adj,0);
        return maxInformTime;
    }
};