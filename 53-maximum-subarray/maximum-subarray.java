class Solution {
    public int maxSubArray(int[] nums) {
        int size=nums.length;
        if(size==0) return 0;
        int sum=0;
        int maxSum=Integer.MIN_VALUE;
        for(int i=0;i<size;++i){
            sum+=nums[i];
            maxSum=Math.max(maxSum,sum);
            if(sum<0) sum=0;
        }
        return maxSum;
    }
}