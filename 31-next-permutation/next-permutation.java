class Solution {
    public static void swap(int[] arr, int i, int j){
        int x=arr[i];
        arr[i]=arr[j];
        arr[j]=x;
    }
    public static void reverse(int [] arr,int idx){
        int len=arr.length;
        int last=len-1;
        while(idx<last){
            swap(arr,idx,last);
            ++idx;
            --last;
        }
    }
    public void nextPermutation(int[] nums) {
        int idx=-1;
        int size=nums.length;
        if(size==0) return;
        //from last figure out first element which is smaller than its previous element
        for(int i=size-1;i>0;--i){
            if(nums[i]>nums[i-1]){
                idx=i-1;
                break;
            }
        }
        for(int i=size-1;i>=0;--i){
            if(idx>=0 && nums[i]>nums[idx]){
                swap(nums, i,idx);
                break;
            }
        }
        reverse(nums,idx+1);

    }
}