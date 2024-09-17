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
    vector<vector<int>>res;
    void dfs(TreeNode *root, vector<int>target, int targetSum, int sum){
        if(root==NULL) return;
        target.push_back(root->val);
        sum+=root->val;
        if(root->left==NULL && root->right==NULL && targetSum==sum){
            res.push_back(target);
        }

        dfs(root->left, target, targetSum, sum);
        dfs(root->right, target, targetSum, sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res.clear();
        dfs(root,{},targetSum,0);
        return res;
    }
};