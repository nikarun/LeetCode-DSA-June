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
    public ListNode rotateRight(ListNode head, int k) {
        ListNode ptr=head;
        if(ptr==null) return ptr;
        int size=0;
        while(ptr!=null){
            ++size;
            ptr=ptr.next;
        }
        k=k%size;
        if(k==0) return head;
        ListNode first=head;
        ListNode sec=head;
        for(int i=0;i<k;++i){
            sec=sec.next;
        }
        if(sec==null) return head;
        ListNode new_head=null;
        while(sec.next!=null){
            first=first.next;
            sec=sec.next;
        }
        new_head=first.next;
        first.next=null;
        sec.next=head;
        return new_head;
    }
}