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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int>post;
        stack<TreeNode*>st;
        while(root || !st.empty()){
            while(root){
                post.push_back(root->val);
                st.push(root);
                root=root->left;
            }
            TreeNode *temp=st.top();
            st.pop();
            root=temp->right;
        }
        return post;
    }
};