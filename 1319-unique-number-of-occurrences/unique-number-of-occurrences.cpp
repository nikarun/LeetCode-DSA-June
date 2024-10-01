class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return true;
        unordered_map<int,int>mp;
        for(int p:arr){
            mp[p]++;
        }
        set<int>s1;
        for(auto it =mp.begin();it!=mp.end();++it){
            s1.insert(it->second);
        }
        cout<<s1.size()<<endl;
        return s1.size()==mp.size();
    }
};