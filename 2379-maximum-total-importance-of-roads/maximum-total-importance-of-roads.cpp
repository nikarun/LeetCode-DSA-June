class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>freq(n,0);
        for(int i=0;i<roads.size();++i){
            freq[roads[i][0]]++;
            freq[roads[i][1]]++;
        }
        sort(freq.begin(),freq.end());
        long long res=0;
        //assign lowest to one with least freq
        for(int i=0;i<n;++i){
            res+=(long long)freq[i]*(i+1);
        }
        return res;
    }
};