class Solution {
public:
    bool isAnagram(string s, int i, int j, string p){
        unordered_map<char,int>mp;
        for(char c:p){
            mp[c]++;
        }
        for(int k=i;k<=j;++k){
            if(mp[s[k]]==0) return false;
            else mp[s[k]]--;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int i=0,j=0;
        int k=p.size();
        unordered_map<char,int>mp;
        for(char c:p){
            mp[c]++;
        }
        vector<int>res;
        int cntr=mp.size();
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0) --cntr;
            }
            if(j-i+1<k) ++j;
            else if(j-i+1==k){
                if(cntr==0){
                    res.push_back(i);
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++; //increase the frequency of reduced characters
                    if(mp[s[i]]==1){
                        ++cntr;
                    }
                }
                ++i;
                ++j;
            }
        }
        return res;
    }
};

// s="cbaebabacd"
// p="abc"

// window of size ->len(p)
// i, j ->sliding window
// i
// bab ->
// brute force ->
// for every window of size n check if it is anagram of p.
// T.c -> n*p;

