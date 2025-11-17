class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return false;
        int first=-1;
        for(int i=0;i<n;++i){
            if(nums[i]==1){
                if(first==-1) first=i;
                else if(i-first<=k) return false;
                first=i;
            }
        }
        return true;
    }
};