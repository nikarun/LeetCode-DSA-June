class Solution {
public:
    vector<vector<int>>dp;
    int lcs(string text1,string text2,int m,int n){
        if(m==0 || n==0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(text1[m-1]==text2[n-1]) return dp[m][n] = 1+lcs(text1,text2,m-1,n-1);
        else return dp[m][n] = max(lcs(text1,text2,m-1,n),lcs(text1,text2,m,n-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;++i){
            for(int j=0;j<=n;++j){
                if(i==0 || j==0) dp[i][j]=0;
                else if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[m][n];

    }
};