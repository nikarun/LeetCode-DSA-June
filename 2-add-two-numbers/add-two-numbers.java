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
    public ListNode reverse(ListNode head){
        if(head==null) return null;
        ListNode prev=null;
        ListNode ptr=head;
        while(ptr!=null){
            ListNode next=ptr.next;
            ptr.next=prev;
            prev=ptr;
            ptr=next;
        }
        return prev;
    }
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // l1=reverse(l1);
        // l2=reverse(l2);
        if(l1==null) return l2;
        if(l2==null) return l1;
        int sum=0;
        int carry=0;
        ListNode head=new ListNode(-1);
        ListNode temp=head;
        while(l1!=null && l2!=null){
            sum=carry+l1.val+l2.val;
            head.next=new ListNode(sum%10);
            carry=sum/10;
            head=head.next;
            l1=l1.next;
            l2=l2.next;
        }
        while(l1!=null){
            sum=carry+l1.val;
            head.next=new ListNode(sum%10);
            carry=sum/10;
            head=head.next;
            l1=l1.next;
        }
        while(l2!=null){
            sum=carry+l2.val;
            head.next=new ListNode(sum%10);
            carry=sum/10;
            head=head.next;
            l2=l2.next;
        }
        if(carry>0){
            head.next=new ListNode(carry);
            
        }
        return temp.next;

    }
}