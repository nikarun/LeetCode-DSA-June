class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        vector<int>dp(n,1);
        int max_len=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1);
                max_len=max(max_len,dp[i]);
            }
        }
        return max(max_len,dp[n-1]);
    }
};