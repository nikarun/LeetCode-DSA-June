class Solution {
    public int binarySearch(String str, int[] nums, int target){
        int n=nums.length;
        if(n==0) return -1;
        int i=0,j=n-1;
        int result=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target){
                result=mid;
                if(str=="FIRST"){
                    j=mid-1;
                }
                else i=mid+1;
            }
            else if(nums[mid]<target){
                i=mid+1;
            }
            else j=mid-1;
        }
        return result;
    }
    public int[] searchRange(int[] nums, int target) {
        int[] res=new int[]{binarySearch("FIRST", nums, target), binarySearch("LAST", nums, target)};
        return res;
    }
}

// 5,7,7,8,8,10