class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int start=0,end=n-1;
        while(start<end-1){
            int mid=start+(end-start)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            else if(nums[mid+1]<nums[mid]) end=mid-1;
            else start=mid+1;
        }
        return nums[start]>nums[end]?start:end;
    }
};