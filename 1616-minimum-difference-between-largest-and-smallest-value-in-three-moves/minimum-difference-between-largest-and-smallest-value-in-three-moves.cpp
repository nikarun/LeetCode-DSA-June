class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0;
        //brute force
        //total 4 cases possible
        //update first 3 elements res will be ->(n-1)-3
        //update first 2 & last elem res ->(n-2)-2
        //update first & last 2 res->(n-3)-3
        //update last 3 ->res->(n-4)-0
        sort(nums.begin(),nums.end());
        int res=INT_MAX;
        res=min(res,nums[n-1]-nums[3]);
        res=min(res,nums[n-2]-nums[2]);
        res=min(res,nums[n-3]-nums[1]);
        res=min(res,nums[n-4]-nums[0]);
        return res;
    }
};