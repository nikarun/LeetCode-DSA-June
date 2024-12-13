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
        ListNode ptr=head;
        int len=0;
        while(ptr!=null){
            ++len;
            ptr=ptr.next;
        }
        if(len<k) return head;
        int temp=k;
        ListNode prev=null;
        ptr=head;
        ListNode next;
        while(ptr!=null && temp-->0){
            next=ptr.next;
            ptr.next=prev;
            prev=ptr;
            ptr=next;
        }
        head.next=reverseKGroup(ptr,k);
        return prev;


    }
}