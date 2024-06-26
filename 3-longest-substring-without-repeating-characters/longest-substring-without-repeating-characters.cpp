class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0;
        unordered_map<char,int>mp;
        int len=0;
        int start=0;
        for(int i=0;i<n;++i){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
            }
            else{
                start=max(start,mp[s[i]]+1);
                mp[s[i]]=i;
            }
            len=max(len,i-start+1);
        }
        return len;
    }
};