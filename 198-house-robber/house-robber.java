class Solution {
    public int rob(int[] nums) {
        int n=nums.length;
        int[] dp=new int[n];
        if(n==1) return nums[0];
        dp[0]=nums[0];
        dp[1]=Math.max(dp[0],nums[1]);
        // if(n==2) return Math.max(dp[0],dp[1]);
        for(int i=2;i<n;++i){                                                                  
            dp[i]=Math.max(dp[i-1],dp[i-2]+nums[i]);
        }
        return Math.max(dp[n-1],dp[n-2]);
    }
}