class Solution {
    public int maxScore(String s) {
        int zeroCount=0;
        int oneCount=0;
        int n=s.length();
        for(int i=0;i<n;++i){
            if(s.charAt(i)=='1') ++oneCount;
        }
        int maxLen=0;
        for(int i=0;i<n-1;++i){
            if(s.charAt(i)=='0') ++zeroCount;
            if(s.charAt(i)=='1') --oneCount;
            maxLen=Math.max(maxLen,zeroCount+oneCount);
        }
        return maxLen;

    }
}