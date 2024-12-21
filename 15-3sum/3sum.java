class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int size=nums.length;
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        for(int i=0;i<size;++i){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=size-1;
            int target = 0-nums[i];
            while(j<k){
                if(nums[j]+nums[k]==target){
                    int[] triplet = new int[]{nums[i], nums[j], nums[k]};
                    res.add(Arrays.stream(triplet).boxed().toList());
                    while(j<k && nums[j]==triplet[1]){
                       ++j;
                   }
                   while(j<k && nums[k]==triplet[2]){
                     --k;
                    }
                }
                else if((nums[j]+nums[k])<target){
                    ++j;
                }
                else{
                    --k;
                }
            }
        }
        return res;
    }
}