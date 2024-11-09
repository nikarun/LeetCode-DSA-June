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
    vector<int> inorderTraversal(TreeNode* root) {
        // stack<int>st;
        vector<int>res;
        stack<TreeNode*>st;
        while(root || !st.empty()){
            while(root) {
                st.push(root);
                root=root->left;
            };
            TreeNode *temp=st.top();
            st.pop();
            res.push_back(temp->val);
            root=temp->right;
        }
        return res;
    }
};