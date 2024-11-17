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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        if(n==0) return NULL;
        int val=preorder[0];
        TreeNode* root=new TreeNode(val);
        if(n==1) return root;
        vector<int>left;
        vector<int>right;
        for(int i=0;i<n;++i){
            if(preorder[i]<val) left.push_back(preorder[i]);
            else if(preorder[i]>val) right.push_back(preorder[i]);
        }
        root->left=bstFromPreorder(left);
        root->right=bstFromPreorder(right);
        return root;
    }
};