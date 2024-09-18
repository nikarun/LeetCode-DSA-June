/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int maxSum=INT_MIN;
        int res=0;
        int lvl=0;
        while(!q.empty()){
            int sum=0;
            int size=q.size();
            ++lvl;
            while(size>0){
                TreeNode *top=q.front();
                q.pop();
                sum+=top->val;
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
                --size;
            }
            if(sum>maxSum){
                res=lvl;
                maxSum=sum;
            }
        }
        return res;
    }
};