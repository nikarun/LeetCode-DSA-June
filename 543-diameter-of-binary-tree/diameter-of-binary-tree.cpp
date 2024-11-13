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
    int maxDiamter=0;
    int dfs(TreeNode *root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        int left=dfs(root->left);
        int right=dfs(root->right);
        maxDiamter=max(maxDiamter,left+right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int h=dfs(root);
        return maxDiamter;
    }
};