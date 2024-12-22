class Solution {
    public int removeDuplicates(int[] nums) {
  int size=nums.length;
  int i=1;
  int j=1;
  while(i<size){
    while(i<size && nums[i]==nums[i-1]) ++i;
   if(i<size) nums[j++]=nums[i];
   ++i;
  }
  return j;

  }        
}
