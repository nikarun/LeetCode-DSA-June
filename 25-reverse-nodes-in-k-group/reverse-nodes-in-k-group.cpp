/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        ListNode *ptr=head;
        while(ptr){
            ++count;
            ptr=ptr->next;
        }
        if(count<k) return head;
        ListNode *prev=NULL, *next=head, *curr=head;
        // ptr=head;
        int p=k;
        while(curr && p>0){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            --p;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};