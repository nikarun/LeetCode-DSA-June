class Solution {
public:
    static bool comp(const pair<int,string>&a,const pair<int,string>&b){
        return a.first>b.first;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        vector<pair<int,string>>vec;
        for(int i=0;i<n;++i){
            vec.push_back({heights[i],names[i]});
        }
        sort(vec.begin(),vec.end(), comp);
        vector<string>res;
        for(auto &p:vec){
            res.push_back(p.second);
        }
        return res;
    }
};