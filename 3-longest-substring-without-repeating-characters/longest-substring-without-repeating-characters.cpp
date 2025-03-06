class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        int res=0;
        unordered_map<char,int>mp;
        while(i<n && j<n){
            if(mp.find(s[j])!=mp.end() && mp[s[j]]>=i){
                i=mp[s[j]]+1;
                mp[s[j]]=j;
            }
            else{
                mp[s[j]]=j;
                res=max(res,j-i+1);
            }
            ++j;
        }
        return res;
    }
};
// "tmmzuxt"

// i=0,j=i+1
// abcabcbb
// i=mp[str[j]]+1
// pwwkew.
//dvdf