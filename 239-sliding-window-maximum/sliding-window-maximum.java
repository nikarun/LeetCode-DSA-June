class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int size=nums.length;
        int[] result=new int[size-k+1];
        Deque<Integer>dq=new ArrayDeque<>();
        int i=0,j=0;
        while(i<size){
            while(!dq.isEmpty() && dq.peekFirst()==i-k) dq.removeFirst(); //when first element is not valid
            while(!dq.isEmpty() && nums[dq.peekLast()]<nums[i]) dq.removeLast();//monotonic
            dq.offerLast(i);
            if(i>=k-1) result[j++]=nums[dq.peekFirst()];
            ++i;
        }
        return result;
    }
}