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
    bool isBStValid=true;
    void dfs(TreeNode *root, TreeNode *lower, TreeNode *higher){
        if(root==NULL) return ;
        dfs(root->left,lower,root);
        if((lower &&  root->val<=lower->val) || (higher && root->val>=higher->val)){
            isBStValid=false;;
        }
        dfs(root->right,root,higher);
        
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        dfs(root,NULL,NULL);
        return isBStValid;
    }
};