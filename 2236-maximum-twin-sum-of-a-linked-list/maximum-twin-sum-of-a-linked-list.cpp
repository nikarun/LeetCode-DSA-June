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
    ListNode* reverse(ListNode *head){
        ListNode *ptr=head,*prev=NULL,*next;
        while(ptr){
            next=ptr->next;
            ptr->next=prev;
            prev=ptr;
            ptr=next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        if(head->next==NULL) return head->val;
        ListNode *slow=head;
        ListNode *fast=head->next->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *temp=reverse(slow->next);
        slow->next=NULL;
        int res=0;
        while(temp && head){
            int sum = temp->val + head->val;
            res=max(res,sum);
            temp=temp->next;
            head=head->next;
        }
        return res;
    }
};