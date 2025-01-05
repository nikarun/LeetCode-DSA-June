class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n=s.length();
        int []line=new int[n+1];
        for(int i=0;i<n+1;++i){
            line[i]=0;
        }
        for(int[] temp:shifts){
            if(temp[2]==1){
                line[temp[0]]++;
                line[temp[1]+1]--;
            }
            else{
                line[temp[0]]--;
                line[temp[1]+1]++;
            }
        }
        for(int i=1;i<=n;++i){
            line[i]+=line[i-1];
        }
        StringBuilder sb = new StringBuilder(s);
        for(int i=0;i<n;++i){
            int incBy=(s.charAt(i)-'a'+line[i])%26;
            incBy=(incBy+26)%26;
            char newChar = (char) ('a' + incBy); 
            sb.setCharAt(i, newChar);
        }
        return sb.toString();
    }
}

// 0-->1, 1(0-->1, 2-->-1)
// 1-->2, 0 (1-->0,3-->0)
// 0-->2, 1 (0-->2, 3 -->-1)
// line[1]=line[1]+line[0]
