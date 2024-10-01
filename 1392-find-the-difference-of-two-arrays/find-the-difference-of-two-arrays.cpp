class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        unordered_map<int,int>mp1;
        for(int p:nums2){
            mp1[p]++;
        }
        unordered_map<int,int>mp2;
        set<int>s1;
        for(int p:nums1){
            mp2[p]++;
            if(mp1[p]==0) s1.insert(p);
        }
        vector<int>res1(s1.begin(),s1.end());
        set<int>s2;
        for(int p:nums2){
            if(mp2[p]==0) s2.insert(p);
        }

        // for(auto it =mp.begin();it!=mp.end();++it){
        //     if(it->second>0){
        //         s2.insert(it->first);
        //     }
        // }
        vector<int>res2(s2.begin(),s2.end());
        return {res1,res2};
    }
};