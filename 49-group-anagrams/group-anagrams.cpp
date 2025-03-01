class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();++i){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(strs[i]);
        }
        vector<vector<string>>res;
        for(auto it=mp.begin();it!=mp.end();++it){
            vector<string>innerRes;
            for(int i=0;i<it->second.size();++i){
                innerRes.push_back(it->second[i]);
            }
            res.push_back(innerRes);
        }
        return res;

    }
};

// ["ate","ate", "ant", "ate", "ant", "abt"]
