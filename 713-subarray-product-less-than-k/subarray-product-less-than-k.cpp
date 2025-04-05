class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        long long pdt=1;
        int len=0;
        for(int i=0;i<n;++i){
            pdt=nums[i];
            if(pdt<k) ++len;
            else continue;
            for(int j=i+1;j<n;++j){
                pdt*=nums[j];
                if(pdt<k) ++len;
                else break;
            }
        }
        return len;
    }
};