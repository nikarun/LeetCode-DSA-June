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
    int dfs(TreeNode *root, int maxValue){
        if(root==NULL) return 0;
        int count=dfs(root->left,max(maxValue,root->val))+dfs(root->right,max(maxValue,root->val));
        if(root->val>=maxValue){
            count=count+1;
        }
        return count;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,-9999999);
    }
};