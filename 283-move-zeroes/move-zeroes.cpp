class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int zeros=0;
        int ans=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0) ++zeros;
            else nums[ans++]=nums[i];
        }
        for(int j=0;j<zeros;++j){
            nums[ans++]=0;
        }

    }
};


// append zeros_count in nums in last
// iterate on arr
