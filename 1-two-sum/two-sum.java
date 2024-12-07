class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer>hMap=new HashMap<Integer,Integer>();
        int n=nums.length;
        for(int i=0;i<n;++i){
            if(hMap.containsKey(target-nums[i])) {
                return new int[]{i,hMap.get(target-nums[i])};
            }
            else{
                hMap.put(nums[i],i);
            }
        }
        return new int[]{-1,-1};
    }
}