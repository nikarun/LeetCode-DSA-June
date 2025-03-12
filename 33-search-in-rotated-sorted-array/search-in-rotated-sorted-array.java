class Solution {
    public int search(int[] nums, int target) {
        int n=nums.length;
        if(n==0) return 0;
        int i=0,j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>=nums[i]){
               if(target>=nums[i] && target<nums[mid]) j=mid-1;
                else i=mid+1;
            }
            else{
                if(target<=nums[j] && target>nums[mid]) i=mid+1;
                else j=mid-1;
            }
        }
        return -1;

    }
}