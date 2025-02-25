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
    vector<int>inorder;
    int idx=0;
    void dfs(TreeNode *root){
        if(root==NULL) return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    } 
    void modifyTree(TreeNode *root){
        if(root==NULL) return;
        modifyTree(root->left);
        root->val=inorder[idx];
        ++idx;
        // cout<<idx<<endl;
        modifyTree(root->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL) return NULL;
        TreeNode *temp=root;
        dfs(root);
        int n=inorder.size();
        for(int i=n-2;i>=0;--i){
            inorder[i]+=inorder[i+1];
        }
        // for(int i=0;i<n;++i){
        //     cout<<inorder[i]<<" ";
        // }

        modifyTree(temp);
        // cout<<endl<<idx<<endl;
        return root;
    }
};

// 0,1,2,3,4,5,6,7,8

// left, root, right
// right, root, left

// dfs
