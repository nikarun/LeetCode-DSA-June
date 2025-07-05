class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return 0;
        unordered_map<int,int>mp;
        int res=-1;
        for(int p:arr){
            mp[p]++;
        }
        for(int p:arr){
            if(mp[p]==p){
                res=max(res,p);
            }
        }
        return res;
    }
};