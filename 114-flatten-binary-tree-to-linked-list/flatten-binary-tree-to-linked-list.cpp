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
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        while(root){
            TreeNode *ptr=root->right;
            TreeNode *temp=root->left;
            root->right=temp;
            root->left=NULL;
            while(temp && temp->right!=NULL) temp=temp->right;
            if(temp) temp->right=ptr;
            else root->right=ptr;
            root=root->right;
        }

    }
};