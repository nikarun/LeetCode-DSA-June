class Solution {
    public int majorityElement(int[] nums) {
        int n=nums.length;
        if(n==0) return 0;
        int cnt=1;
        int elem=nums[0];
        for(int i=1;i<n;++i){
            if(nums[i]==elem) ++cnt;
            else --cnt;
            if(cnt<0) {
                elem=nums[i];
                cnt=1;
            }
        }
        return elem;
        
    }
}