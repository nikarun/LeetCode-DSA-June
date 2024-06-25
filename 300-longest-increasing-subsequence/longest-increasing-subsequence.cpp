class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        int res=0;
        for(int i=0;i<n;++i){
            dp[i]=1;
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]){
                    dp[i]=dp[i]>dp[j]+1?dp[i]:dp[j]+1;
                    res=max(res,dp[i]);
                }
            }
        }
        return max(res,dp[n-1]);
    }
};