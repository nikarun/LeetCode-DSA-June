class Solution {
    public int waysToSplitArray(int[] nums) {
        int n=nums.length;
        long sum=0;
        for(int i=0;i<n;++i){
            sum+=nums[i];
        }
        long leftSum=0;
        int res=0;
        for(int i=0;i<n-1;++i){
           leftSum+=nums[i];
           long rightSum=sum-leftSum;
           if(leftSum>=rightSum) ++res;
        }
        return res;
    }
}