class Solution {
    public int countPalindromicSubsequence(String s) {
        int [][] alpha=new int [26][2];
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 2; j++) {
                alpha[i][j] = -1;
            }
        }
        int n=s.length();
        for(int i=0;i<n;++i){
            if(alpha[s.charAt(i)-'a'][0]==-1) alpha[s.charAt(i)-'a'][0]=i; //first index of this element
            else alpha[s.charAt(i)-'a'][1]=i; //last index of this element
        }
        int res=0;
        for(int i=0;i<26;++i){
            if(alpha[i][1]!=-1){
                //find unique character between first & last.
                Set<Integer>st=new HashSet<>();
                for(int j=alpha[i][0]+1;j<alpha[i][1];++j){
                    st.add(s.charAt(j)-'a');
                }
                res+=st.size();
            }
        }
    return res;
    }
}

//for 3 letter palindrome -->first & last letter should be same so
// for each same character find unique character between this two