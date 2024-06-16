/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,bool>mp;
        while(headA){
            mp[headA]=true;
            // if(mp.find(headB)!=mp.end()){
            //     return headB;
            // }
            headA=headA->next;
            // headB=headB->next;
        }
        while(headB){
            if(mp.find(headB)!=mp.end()){
                return headB;
            }
            headB=headB->next;
        }
        return headB;
    }
};