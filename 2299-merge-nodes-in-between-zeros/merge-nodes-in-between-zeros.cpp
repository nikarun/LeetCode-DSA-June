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
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL) return head;
        ListNode *ptr1=head,*ptr2=head;
        ListNode *temp=NULL, *tpt;
        while(ptr1->next){
            int res=0;
            ptr2=ptr1->next;
            while(ptr2->val!=0){
                res+=ptr2->val;
                ptr2=ptr2->next;
            }
            if(temp==NULL){
                temp=new ListNode(res);
                tpt=temp;
            }
            else{
                temp->next=new ListNode(res);
                temp=temp->next;
            }
            ptr1->next->next=ptr2;
            ptr1=ptr2;
        }
        return tpt;
    }
};