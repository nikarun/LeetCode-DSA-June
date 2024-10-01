class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        unordered_set<int>s1(nums1.begin(),nums1.end());
        unordered_set<int>s2(nums2.begin(),nums2.end());
        vector<int>res1;
        vector<int>res2;
        for(int p:s1){
            if(s2.count(p)==0) res1.push_back(p);
        }
        for(int p:s2){
            if(s1.count(p)==0) res2.push_back(p);
        }
        return {res1,res2};
 
    }
};