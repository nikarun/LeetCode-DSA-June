class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return (edges[0][0]==edges[1][0] || edges[0][0] == edges[1][1])?edges[0][0]:edges[0][1];
        // unordered_map<int,int>mp;
        // for(int i=0;i<edges.size();++i){
        //     mp[edges[i][0]]++;
        //     mp[edges[i][1]]++;
        // }
        // int max_freq=0;
        // int elem;
        // for(auto it=mp.begin();it!=mp.end();++it){
        //     if(it->second>max_freq){
        //         max_freq=it->second;
        //         elem=it->first;
        //     }
        // }
        // return elem;
    }
};