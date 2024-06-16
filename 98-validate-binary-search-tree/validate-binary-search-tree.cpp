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
    bool dfs(TreeNode *root, int *upper, int *lower){
        if(!root) return true;
        if(upper){
            if(root->val>=*upper) return false;
        }
        if(lower){
            if(root->val<=*lower) return false;
        }
        return dfs(root->left,&(root->val),lower) && dfs(root->right,upper,&(root->val));
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        return dfs(root, NULL, NULL);
    }
};