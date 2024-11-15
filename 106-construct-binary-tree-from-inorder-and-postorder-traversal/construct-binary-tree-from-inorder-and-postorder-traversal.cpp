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
    int pos;
    unordered_map<int,int>mp;
    TreeNode *constructTree(vector<int>&inorder,int si,int ei, vector<int>&postorder){
        if(si>ei || pos<0) return NULL;
        cout<<pos<<endl;
        int val=postorder[pos--];
        TreeNode *node=new TreeNode(val);
        int idx=mp[val];
        node->right=constructTree(inorder,idx+1,ei,postorder);
        node->left=constructTree(inorder, si,idx-1,postorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        if(n==0) return NULL;
        for(int i=0;i<n;++i){
            mp[inorder[i]]=i;
        }
        pos=n-1;
        return constructTree(inorder,0,n-1,postorder);
    }
};