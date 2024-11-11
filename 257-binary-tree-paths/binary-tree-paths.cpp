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
    vector<string>path;
    void dfs(TreeNode *root,string str){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) {
            str+=to_string(root->val);
            path.push_back(str);
            str="";
        }
        str+=to_string(root->val);
        str+="->";
        // if(root->left || root->right) str+='->';
        dfs(root->left,str);
        dfs(root->right,str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL) return {};
        dfs(root,"");
        return path;
    }
};