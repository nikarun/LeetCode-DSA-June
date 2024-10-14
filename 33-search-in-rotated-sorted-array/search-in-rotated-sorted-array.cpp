class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) return 0;
        int start=0,end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>=nums[start]){
                if(target>=nums[start] && target<nums[mid]) end=mid;
                else start=mid+1;
            }
            else{
                if(target<=nums[end] && target>nums[mid]) start=mid+1;
                else end=mid;
            }
        }
        return -1;
    }
};