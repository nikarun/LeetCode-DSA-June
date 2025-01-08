class Solution {
    public boolean isPrefixAndSuffix(String word1, String word2){
        if(word2.startsWith(word1) && word2.endsWith(word1)) return true;
        return false;
    }
    public int countPrefixSuffixPairs(String[] words) {
        int n=words.length;
        int res=0;
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                if(isPrefixAndSuffix(words[i],words[j])) ++res;
            }
        }
        return res;
    }
}