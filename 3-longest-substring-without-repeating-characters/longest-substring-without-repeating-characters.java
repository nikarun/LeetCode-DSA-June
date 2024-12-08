class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character,Integer>hMap=new HashMap<>();
        int n=s.length();
        int maxLen=0;
        int j=0;
        for(int i=0;i<n;++i){
            if(hMap.containsKey(s.charAt(i))){
                j=Math.max(hMap.get(s.charAt(i))+1,j);
                // maxLen=Math.max(maxLen,i-hMap.get(s.charAt(i)));
            }
            maxLen=Math.max(maxLen,i-j+1);
            hMap.put(s.charAt(i),i);
        }
        return maxLen;
    }
}