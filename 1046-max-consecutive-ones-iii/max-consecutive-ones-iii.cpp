class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return 0;
        int start=0,zeros=0;
        int res=0;
        for(int i=0;i<n;++i){
            if(nums[i]==0) ++zeros;
            if(zeros>k){
                res=max(res,i-start);
                if(nums[start]==0) --zeros;
                ++start;
            }
        }
        return max(res,n-start);
    }
};