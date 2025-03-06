class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(m>n) return "";
        int k=0;
        unordered_map<char,int>mp; //keps track of t
        unordered_map<char,int>window; //keeps track of window
        int min_len=INT_MAX;
        string res;
        for(char c:t){
            mp[c]++;
        }
        for(int slow=0,fast=0;fast<n;++fast){
            if(mp.find(s[fast])!=mp.end()){
                window[s[fast]]++;
                if(window[s[fast]]<=mp[s[fast]]){
                    ++k;
                }
            }
            if(k>=m){
                while(mp.find(s[slow])==mp.end() || window[s[slow]]>mp[s[slow]]){
                    window[s[slow]]--;
                    ++slow;
                }
                if(fast-slow+1<min_len){
                    min_len=fast-slow+1;
                    res=s.substr(slow,min_len);
                }
            }
        }
        return res;
    }
};


// s = "ADOBECODEBANC", t = "ABC"

// N^2

// "BANC"
// ""