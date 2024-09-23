class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        vector<int>dp(n);
        dp[0]=nums[0];
        if(n<=1) return nums[0];
        else if(n==2) return max(nums[0],nums[1]);
        dp[1]=max(nums[1],nums[0]);
        int amt=max(dp[1],dp[0]);
        for(int i=2;i<n;++i){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return max(dp[n-1],dp[n-2]);
    }
};