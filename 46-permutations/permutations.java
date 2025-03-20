class Solution {
    public List<List<Integer>>res=new ArrayList<>();
    public void backTrack(List<Integer>l1, int[] nums){
        int n=nums.length;
        if(l1.size()==n) res.add(new ArrayList<>(l1));
        else{
            for(int i=0;i<n;++i){
                if(l1.contains(nums[i])) continue;
                l1.add(nums[i]);
                backTrack(l1,nums);
                l1.remove(l1.size()-1);
            }
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        int n=nums.length;
        List<Integer>l1=new ArrayList<>();
        backTrack(l1,nums);
        return res;
    }
}