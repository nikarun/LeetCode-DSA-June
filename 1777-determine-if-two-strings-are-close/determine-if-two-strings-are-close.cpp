class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        unordered_map<char,int>mp1;
        for(char p:word2){
            mp1[p]++;
        }
        unordered_map<char,int>mp2;

        for(char t:word1){
            mp2[t]++;
            if(mp1[t]==0) return false;
        }
        vector<int>vec1;
        vector<int>vec2;
        for(auto it=mp1.begin();it!=mp1.end();++it){
            vec1.push_back(it->second);
        }
        for(auto it=mp2.begin();it!=mp2.end();++it){
            vec2.push_back(it->second);
        }
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());
        return vec1==vec2;
        // return true;
    }
};