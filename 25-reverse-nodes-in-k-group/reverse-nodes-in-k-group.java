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
    public ListNode reverseKGroup(ListNode head, int k) {
        int size=0;
        ListNode ptr=head;
        while(ptr!=null){
            ptr=ptr.next;
            ++size;
        }
        if(k>size) return head;
        int temp=k;
        ListNode prev=null;
        ptr=head;
        // ListNode next;
        while(temp>0 && ptr!=null){
            ListNode next=ptr.next;
            ptr.next=prev;
            prev=ptr;
            ptr=next;
            --temp;
        }
        head.next=reverseKGroup(ptr,k);
        return prev;
    }
}