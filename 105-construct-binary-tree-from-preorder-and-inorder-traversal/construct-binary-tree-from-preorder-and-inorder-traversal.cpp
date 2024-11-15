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
    int pos=0;
    unordered_map<int,int>mp;
    TreeNode *constructTree(vector<int>&inorder, int si, int ei, vector<int>& preorder){
        if(si>ei) return NULL;
        cout<<pos<<endl;
        int val=preorder[pos++];
        TreeNode *root=new TreeNode(val);
        int idx=mp[val];
        root->left=constructTree(inorder,si,idx-1,preorder);
        root->right=constructTree(inorder,idx+1,ei,preorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        if(n==0) return NULL;
        for(int i=0;i<n;++i){
            mp[inorder[i]]=i;
        }
        return constructTree(inorder,0,n-1,preorder);
        }

};