class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        Map<Integer,Integer>mp=new HashMap<Integer,Integer>();
        int n=words.length;
        int cntr=0;
        char[] vowels = {'a', 'e', 'i', 'o', 'u'};
        for(int i=0;i<n;++i){
            String curr=words[i];
            int size=curr.length();
            boolean isFirstVowel = false;
            boolean isLastVowel = false;
            char firstChar = curr.charAt(0);
            char lastChar = curr.charAt(size - 1);
            for (char vowel : vowels) {
                if (vowel == firstChar) {
                    isFirstVowel = true;
                    break;
                }
            }

            for (char vowel : vowels) {
                if (vowel == lastChar) {
                    isLastVowel = true;
                    break;
                }
            }
            if(isFirstVowel && isLastVowel){
                ++cntr;
            }
            mp.put(i,cntr);
        }
        int idx=0;
        int[] res = new int[queries.length];
        for(int j=0;j<queries.length;++j){
            int temp=0;
            int first=mp.get(queries[j][0]);
            int last=mp.get(queries[j][1]);
            System.out.println(last);
            System.out.println(first);
            if(mp.containsKey(queries[j][0]-1)){
                int count=last-mp.get(queries[j][0]-1);
                res[idx]=count;
            }
            else{
                res[idx]=last;
            }
            ++idx;
        }
        return res;
    }
}