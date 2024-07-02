class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums1.size();++i){
            mp[nums1[i]]++;
        }
        vector<int>res;
        for(int num:nums2){
            if(mp[num]>0){
                res.push_back(num);
                mp[num]--;
            }
        }
        return res;
    }
};