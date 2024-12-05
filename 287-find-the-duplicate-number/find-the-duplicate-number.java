class Solution {
    public int findDuplicate(int[] nums) {
        int n=nums.length;
        HashMap<Integer,Integer>mp=new HashMap<Integer,Integer>();
        for(int i=0;i<n;++i){
            if(mp.containsKey(nums[i])) return nums[i];
            mp.put(nums[i],i);
        }
        return -1;
    }
}