class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        //bring elements to their positions.
        for(int i=0;i<n;++i){
            while(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;++i){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};
// n=6
// [-1,4,2,1,9,10]
// // [-1,1,2,4,9,10]
// // [-1,2,1,4,9,10]