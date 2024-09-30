class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k=1;
        int start=0,n=nums.size();
        int res=0,zeros=0;
        for(int i=0;i<n;++i){
            if(nums[i]==0) ++zeros;
            if(zeros>k){
                res=max(res,i-start-1);
                if(nums[start]==0) --zeros;
                ++start;
            }
        }
        return max(res,n-start-1);

    }
};