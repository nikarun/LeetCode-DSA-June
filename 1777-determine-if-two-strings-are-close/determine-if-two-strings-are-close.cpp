class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        vector<int>w1(26,0);
        vector<int>w2(26,0);
        set<char>s1;
        set<char>s2;
        for(char p:word1){
            s1.insert(p);
            w1[p-'a']++;
        }

        for(char p:word2){
            s2.insert(p);
            w2[p-'a']++;
        }
        sort(w1.begin(),w1.end());
        sort(w2.begin(),w2.end());
        return w1==w2 && s1==s2;
        // return true;
    }
};