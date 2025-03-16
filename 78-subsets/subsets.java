class Solution {
    public List<List<Integer>>res=new ArrayList<>();
    public void generateSubsets(ArrayList<Integer>l1, int[] nums, int start){
        // if(start==nums.length) return;
        res.add(new ArrayList<>(l1));
        for(int i=start;i<nums.length;++i){
            l1.add(nums[i]);
            generateSubsets(l1,nums,i+1);
            l1.remove(l1.size()-1);
        }
    }
    public List<List<Integer>> subsets(int[] nums) {
        int n=nums.length;
        ArrayList<Integer>l1=new ArrayList<>();
        generateSubsets(l1,nums,0);
        return res;
        
    }
}