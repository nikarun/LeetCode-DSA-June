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
    bool isPalindrome(ListNode* head) {
       if(head==NULL || head->next==NULL) return true;
       ListNode* slow=head,*fast=head;
       while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
       } 
       ListNode *ptr=head,*prev=NULL,*next=head;
       while(ptr!=slow){
        next=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=next;
       }
    //    prev->next=NULL;
       if(fast!=NULL){
        slow=slow->next;
       }
        while(slow && prev){
            cout<<slow->val<<endl<<prev->val;
            if(slow->val!=prev->val) return false;
            slow=slow->next;
            prev=prev->next;
        }
        return true;
    }
};