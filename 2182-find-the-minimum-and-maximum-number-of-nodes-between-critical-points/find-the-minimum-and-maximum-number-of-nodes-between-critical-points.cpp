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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>pts;
        ListNode *prev= NULL;
        ListNode *ptr=head;
        int pos=0;
        while(ptr!=NULL && ptr->next!=NULL){
            if(prev!=NULL){
            if((ptr->val>prev->val && ptr->val>ptr->next->val) || (ptr->val<prev->val && ptr->val<ptr->next->val)){
                pts.push_back(pos);
            }
            }
            prev=ptr;
            ptr=ptr->next;
            pos+=1;
        }
        if(pts.size()<2){
            return {-1,-1};
        }
        int n=pts.size();
        int maxd=pts[n-1]-pts[0];
        int mind=INT_MAX;
        for(int i=1;i<n;++i){
            mind=min(mind,pts[i]-pts[i-1]);
        }
        return {mind,maxd};
    }
};