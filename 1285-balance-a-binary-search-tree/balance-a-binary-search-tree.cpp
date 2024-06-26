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
        if(!root) return;
        dfs(root->left,inorder);
        inorder.push_back(root);
        dfs(root->right,inorder);
    }
    TreeNode* binary_search(vector<TreeNode*>&inorder,int s,int e){
       if(s<=e){
        int mid=s+(e-s)/2;
        TreeNode *root=inorder[mid];
        root->left=binary_search(inorder,s,mid-1);
        root->right=binary_search(inorder,mid+1,e);
        return root;
       }
       return NULL;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL) return NULL;
        vector<TreeNode*>inorder;
        dfs(root,inorder);
        int s=0,e=inorder.size()-1;
        return binary_search(inorder,s,e);
    }
};