class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int oneCount=0;
        int size=nums.length;
        int i=0;
        while(i<size){
            int ones=0;
            while(i<size && nums[i]==1){
                ++ones;
                ++i;
            }
            oneCount=Math.max(ones,oneCount);
            ++i;
        }
        return oneCount;
    }
}