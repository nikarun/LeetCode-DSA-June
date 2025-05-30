class Solution {
public:
    // int lcs(string text1, int m, string text2, int n){
    //     if(m==0 || n==0) return 0;
    //     if(text1[m-1]==text2[n-1]) return 1+lcs(text1,m-1,text2,n-1);
    //     else return max(lcs(text1,m-1,text2,n),lcs(text1,m,text2,n-1));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        // return lcs(text1,m, text2, n);
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};