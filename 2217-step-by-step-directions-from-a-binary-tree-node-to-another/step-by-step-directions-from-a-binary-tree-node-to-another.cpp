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
    bool dfs(TreeNode* root, int value, string &res){
        if(root==NULL) return false;
        if(root->val==value) return true;
        res.push_back('L');
        if(dfs(root->left,value,res)) return true;
        res.pop_back();
        res.push_back('R');
        if(dfs(root->right,value,res)) return true;
        res.pop_back();
        return false;

        }
    
    TreeNode* findLCA(TreeNode*root,int p,int q)
    {
        if (!root || root->val == p || root->val == q) {
            return root;
        }
        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);
        if (left && right) {
            return root;
        }
        return left ? left : right;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        if(root==NULL) return "";
        TreeNode* lc=findLCA(root, startValue, destValue);
        cout<<lc->val<<endl;
        string ls="";
        string ds="";
        dfs(lc, startValue, ls);
        dfs(lc, destValue, ds);
        for(auto &p:ls){
            p='U';
        }
        return ls+ds;
        
    }
};

// 5-->3
// LL
// 5-->6
// RL
// if same side 
// start from one node go to another node
// else 
// U till root node & 