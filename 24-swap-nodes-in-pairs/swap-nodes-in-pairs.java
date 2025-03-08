/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public static int k=2;
    public ListNode swapPairs(ListNode head) {
        if(head==null) return null;
        int size=0;
        ListNode ptr=head;
        while(ptr!=null){
            ptr=ptr.next;
            ++size;
        }
        if(k>size) return head;
        ptr=head;
        ListNode prev=null;
        int temp=k;
        while(temp>0 && ptr!=null){
            ListNode next=ptr.next;
            ptr.next=prev;
            prev=ptr;
            ptr=next;
            --temp;
        }
        head.next=swapPairs(ptr);
        return prev;
    }
}
//reverse every k group.


