class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        //this is same as subset sum with diff k problem
        //which is same as subset sum with sum as range+diff/2
        int sum=0;
        for(int p:nums){
            sum+=p;
        }
        cout<<sum<<endl;
        if((sum+target)%2!=0 || abs(sum)<abs(target)) return 0;
        int target_sum=(sum+target)/2;
        cout<<target_sum<<endl;
        int dp[n+1][target_sum+1];
        // for(int i=0;i<=target_sum;++i){
        //     dp[0][i]=0;
        // }
        // for(int j=0;j<=n;++j){
        //     dp[j][0]=1;
        // }
        for(int i=0;i<=n;++i){
            for(int j=0;j<=target_sum;++j){
                if(i==0 && j==0) dp[i][j]=1;
                else if(i==0) dp[i][j]=0;
                else{
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
                else dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][target_sum];
    }
};