class Solution {
public:
    int inf=1e9;
    void short_distance(vector<vector<int>>&adj){
        int n=adj.size();
        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=26;
        vector<vector<int>>adj(n,vector<int>(n,inf));
        for(int i=0;i<original.size();++i){
            int from = original[i]-'a';
            int to = changed[i]-'a';
            adj[from][to]=min(cost[i],adj[from][to]);
        }
        short_distance(adj);
        long long res=0;
        for(int i=0;i<source.size();++i){
            int from = source[i]-'a';
            int to = target[i]-'a';
            if(from!=to){
                if(adj[from][to]==inf){
                    return -1;
                }
                else{
                    res+=adj[source[i]-'a'][target[i]-'a'];
                }
            }
        }

        return res;
    }
};