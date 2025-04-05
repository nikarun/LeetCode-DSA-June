class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return 0;
        long long pdt=1;
        int len=0;
        int i=0,j=0;
        for(j=0;j<n;++j){
            pdt*=nums[j];
            while(i<=j && pdt>=k){
                pdt=pdt/nums[i];
                ++i;
            }
            len+=(j-i+1);
        }
        return len;
    }
};