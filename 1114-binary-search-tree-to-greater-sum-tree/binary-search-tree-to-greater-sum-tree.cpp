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
    void dfs(TreeNode *root, int& cnt){
        if(root==NULL) return;
        dfs(root->right,cnt);
        root->val+=cnt;
        cnt=root->val;
        dfs(root->left,cnt);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL) return NULL;
        if(root->left == NULL && root->right==NULL) return root;
        int cnt=0;
        dfs(root,cnt);
        return root;
    }
};