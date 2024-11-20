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
    unordered_map<int,bool>mp;
    bool isFound=false;
    void dfs(TreeNode *root, int k){
        if(root==NULL) return;
        dfs(root->left,k);
        if(mp.find(k-root->val)!=mp.end()) isFound=true;
        mp[root->val]=true;
        dfs(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        dfs(root,k);
        return isFound;

    }
};