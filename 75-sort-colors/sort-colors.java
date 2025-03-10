class Solution {
    public void sortColors(int[] nums) {
        int n=nums.length;
        int i=0,j=n-1;
        int k=0;
        while(k<n){
            // [0,1,2]
            // k=1,j=1
            if(i<=j && nums[k]==0){
                int temp=nums[i];
                nums[i]=nums[k];
                nums[k]=temp;
                ++i;
                ++k;
            }
            else if(j>=k && nums[k]==2){
                int temp=nums[j];
                nums[j]=nums[k];
                nums[k]=temp;
                --j;
            }
            else ++k;
        }
    }
}

// i=0,j=5
// k=0
// [2,0,2,1,1,0]
// [0,0,2,1,1,2]
// k=