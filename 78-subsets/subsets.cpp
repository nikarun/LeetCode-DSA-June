class Solution {
public:
    void backtrack(vector<vector<int>> &vec, vector<int>&temp, vector<int>nums,int start){
        vec.push_back(temp);
        for(int i=start;i<nums.size();++i){
            temp.push_back(nums[i]);
            backtrack(vec,temp,nums,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>vec;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        backtrack(vec,temp,nums,0);
        return vec;
    }
};