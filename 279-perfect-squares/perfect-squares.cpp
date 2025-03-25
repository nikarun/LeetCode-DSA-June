class Solution {
public:
    int numSquares(int n) {
        if(n==0) return 0;
        vector<int>dp;
        for(int i=1;i<=n;++i){
            if(i*i<=n){
                dp.push_back(i*i);
            }
            else break;
        }
        vector<int>coin_change(n+1,n+1);
        coin_change[0]=0;
        for(int i=1;i<=n;++i){
            for(int j=0;j<dp.size();++j){
                if(dp[j]<=i){
                    coin_change[i]=min(coin_change[i],coin_change[i-dp[j]]+1);
                }
            }
        }
        return coin_change[n];
    }
};