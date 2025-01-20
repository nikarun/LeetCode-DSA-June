class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>>mp;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                mp[mat[i][j]]={i,j};
            }
        }
        unordered_map<int,int>rowFreq;
        unordered_map<int,int>colFreq;
        for(int i=0;i<arr.size();++i){
            int elem=arr[i];
            pair<int,int>p=mp[elem];
            cout<<p.first<<" "<<p.second<<endl;
            rowFreq[p.first]++;
             colFreq[p.second]++;
            if(rowFreq[p.first]==n || colFreq[p.second]==m) return i;
        }
        return -1;


    }
};