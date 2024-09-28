class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        for(int z:nums){
            if(mp[k-z]>0){
                mp[k-z]--;
                if(mp[z]>0) ++cnt;
                mp[z]--;
            }
        }
        return cnt;
      
    }
};