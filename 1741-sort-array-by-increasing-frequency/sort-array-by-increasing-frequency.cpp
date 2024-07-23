class Solution {
public:
    static bool comp(const pair<int,int>&a, const pair<int,int>&b){
        return a.second!=b.second?a.second<b.second:a.first>b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
       int n=nums.size();
       map<int,int>mp;
       for(int i=0;i<n;++i){
        mp[nums[i]]++;
       }
       vector<pair<int,int>>vec;
       for(auto it=mp.begin();it!=mp.end();++it){
        vec.push_back({it->first,it->second});
       }
       sort(vec.begin(),vec.end(),comp);
       vector<int>res;
    //    for(int i=0;i<n;++i){
    //     cout<<vec[i].first<<" "<<vec[i].second<<endl;
    //    }
       for(int i=0;i<vec.size();++i){
        pair<int,int>p=vec[i];
        for(int j=0;j<p.second;++j){
            res.push_back(p.first);
        }
       }
       return res;

    }
};