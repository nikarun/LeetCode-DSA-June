class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int res=INT_MIN;
        int sum=0;
        for(int p:nums){
            sum+=p;
            res=max(res,sum);
            if(sum<0) sum=0;
        }
        return res;

    }
};