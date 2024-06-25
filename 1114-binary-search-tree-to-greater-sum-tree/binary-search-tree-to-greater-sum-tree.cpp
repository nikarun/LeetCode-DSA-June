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
    void dfs(TreeNode *root, vector<TreeNode*>&inorder){
        if(root==NULL) return;
        dfs(root->left,inorder);
        inorder.push_back(root);
        dfs(root->right,inorder);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL) return NULL;
        if(root->left == NULL && root->right==NULL) return root;
        vector<TreeNode*>inorder;
        dfs(root,inorder);
        int n=inorder.size();
        for(int i=n-2;i>=0;--i){
            inorder[i]->val=inorder[i]->val+inorder[i+1]->val;
        }
        return root;
    }
};