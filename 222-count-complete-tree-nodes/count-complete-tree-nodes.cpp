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
    int countNodes(TreeNode* root) {
        int cntr=0;
        if(root==NULL) return 0;
        int lh=0;
        TreeNode *left=root;
        while(left){
            ++lh;
            left=left->left;
        }
        int rh=0;
        TreeNode *right=root;
        while(right){
            ++rh;
            right=right->right;
        }
        if(lh==rh){
            return pow(2,lh)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};