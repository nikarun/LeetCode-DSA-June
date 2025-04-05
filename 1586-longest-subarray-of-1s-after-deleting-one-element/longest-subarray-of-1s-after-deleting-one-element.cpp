class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int i=0,j=0,res=0;
        int zeros=0;
        for(j=0;j<n;++j){
            if(nums[j]==0) ++zeros;
            while(i<n && zeros>1){
                if(nums[i]==0){
                    ++i;
                    --zeros;
                }
                else{
                    ++i;
                }
            }
            res=max(res,j-i);
        }
        return res;
    }
};