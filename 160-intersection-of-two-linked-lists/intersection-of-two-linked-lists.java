/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int l1=0;
        int l2=0;
        ListNode ptr1=headA;
        ListNode ptr2=headB;
        while(ptr1!=null){
            ptr1=ptr1.next;
            ++l1;
        }
        while(ptr2!=null){
            ptr2=ptr2.next;
            ++l2;
        }
        ListNode first;
        ListNode second;
        int k;
        if(l1>l2){
            first=headA;
            second=headB;
            k=l1-l2;
        }
        else{
            first=headB;
            second=headA;
            k=l2-l1;
        }
        while(k-->0){
            first=first.next;
        }
        while(first!=null && second!=null){
            if(first==second) return first;
            first=first.next;
            second=second.next;
        }
        return null;
        
    }
}