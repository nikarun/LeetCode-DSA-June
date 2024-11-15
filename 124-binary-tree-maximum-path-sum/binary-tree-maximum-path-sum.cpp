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
    int maxSum=INT_MIN;
    int dfs(TreeNode *root){
        if(root==NULL) return 0;
        int leftSum=dfs(root->left);
        int rightSum=dfs(root->right);
        if(leftSum<0) leftSum=0;
        if(rightSum<0) rightSum=0;
        maxSum=max(maxSum,leftSum+rightSum+root->val);
        return max(leftSum,rightSum)+root->val;
    } 
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int sum=0;
        dfs(root);
        return maxSum;
    }
};