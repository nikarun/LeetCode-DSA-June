import java.util.*;

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        //use dequeue indescending order 
        int size=nums.length;
        int[] result = new int[size - k + 1];

        Deque<Integer>dq = new ArrayDeque<>();
        int j=0;
        for(int i=0;i<size;++i){
            while(!dq.isEmpty() && i-k==dq.peekFirst()) dq.removeFirst();
            while(!dq.isEmpty() && nums[dq.peekLast()]<nums[i]) dq.removeLast();
            dq.offerLast(i);
            if(i>=k-1) result[j++]=nums[dq.peekFirst()];
        }
        return result;
    }
}