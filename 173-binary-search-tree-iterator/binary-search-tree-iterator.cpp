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
class BSTIterator {
public:
    queue<TreeNode*>q;
    TreeNode *ptr=NULL;
    void dfs(TreeNode *root){
        if(root==NULL) return;
        dfs(root->left);
        q.push(root);
        dfs(root->right);
    }
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        TreeNode *temp=q.front();
        q.pop();
        ptr=temp;
        return temp->val;
    }
    
    bool hasNext() {
        if(q.empty()) return false;
        else return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */