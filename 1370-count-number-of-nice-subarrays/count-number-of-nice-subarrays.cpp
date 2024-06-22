class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum=0;
        int nice=0;
        mp[0]=1;
        for(int i=0;i<n;++i){
            sum+=nums[i]%2;
            nice+=mp[sum-k];
            mp[sum]++;
        }
        return nice;
    }
};