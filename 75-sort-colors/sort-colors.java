class Solution {
    public static void swap(int[] nums, int i, int j){
        int p=nums[i];
        nums[i]=nums[j];
        nums[j]=p;
    }
    public void sortColors(int[] nums) {
        int n=nums.length;
        int i=0,j=0,k=n-1;
        while(j<n){
            if(i<=j && nums[j]==0){
                swap(nums,i,j);
                ++i;
                ++j;
            }
            else if(k>=j && nums[j]==2){
                swap(nums,j,k);
                --k;
            }
            else ++j;
        }

    }
}



// 2,0,.1
// 1,0,2