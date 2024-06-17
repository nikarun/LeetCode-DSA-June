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
    int max_height=0; 
    // void dfs(TreeNode *root, int &h){
    //     if(root==NULL) return;
    //     dfs(root->left,h);
    //     max_height=max(max_height,h);
    //     dfs(root->right,(h+1));
    // }
    int maxDepth(TreeNode* root) {
        max_height=0;
        if(root==NULL) return 0;
        int h=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            while(size-- > 0){
                TreeNode *front=q.front();
                q.pop();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ++h;
        }
        return h;
    }
};