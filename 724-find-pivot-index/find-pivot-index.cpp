class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int rightSum=0; 
        for(int i=n-1;i>=0;--i){
            rightSum+=nums[i];
        }
        int leftSum=0;
        for(int i=0;i<n;++i){
            leftSum+=nums[i];
            if(leftSum==rightSum) return i;
            rightSum-=nums[i];
        }
        return -1;
    }
};