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
        if(head==NULL) return NULL;
        int len=0;
        ListNode* ptr=head;
        while(ptr){
            ++len;
            ptr=ptr->next;
        }
        if(k>len) return head;
        int t=k;
        ListNode *prev=NULL;
        ptr=head;
        while(ptr && --t>=0){
            ListNode *next=ptr->next;
            ptr->next=prev;
            prev=ptr;
            ptr=next;
        }
        head->next=reverseKGroup(ptr,k);
        return prev;
    }
};