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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        int max_width=1;
        while(!q.empty()){
            int start_idx = q.front().second;
            int last_idx = q.back().second;
            max_width = max(max_width, last_idx-start_idx + 1);
            int size = q.size();
            for(int i=0;i<size;++i){
                pair<TreeNode*,int>p=q.front();
                int idx = p.second-start_idx;
                 q.pop();
                if(p.first->left){
                    q.push({p.first->left, (long long)2*idx + 1});
                }
                if(p.first->right){
                    q.push({p.first->right, (long long)2*idx + 2});
                }
               
            }
        }
        return max_width;
    }
};