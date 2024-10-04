class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0;
        unordered_map<char,int>mp;
        int i=0,res=0;
        for(int j=0;j<n;++j){
            if(mp.find(s[j])!=mp.end()){
                i=max(i,mp[s[j]]+1);
            }
            res=max(res,j-i+1);
            mp[s[j]]=j;
        }
        return res;
    }
};