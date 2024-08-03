class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n=target.size();
        int m=arr.size();
        if(m!=n) return false;
        unordered_map<int,int>mp;
        for(int i=0;i<m;++i){
            mp[arr[i]]++;
        }
        for(int j=0;j<m;++j){
            if(mp[target[j]]==0) return false;
            mp[target[j]]--;
        }
        return true;
    }
};


