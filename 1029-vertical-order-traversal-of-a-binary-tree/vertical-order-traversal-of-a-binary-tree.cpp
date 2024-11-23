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
public:map<int,vector<pair<int,int>>>m;
    void preorder(TreeNode *root,int hd,int vl)
    {
    if(root==NULL) return;
        m[vl].push_back({root->val,hd});
        preorder(root->left,hd-1,vl+1);
        preorder(root->right,hd+1,vl+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL) return{};
        preorder(root,0,0);
        map<int,vector<int>>mp;
        vector<vector<int>>v;
        for(auto e:m)
        {
            vector<pair<int,int>>vl=e.second;
            sort(vl.begin(),vl.end());
            for(auto s:vl){
                if(mp.find(s.second)!=mp.end()){
                    mp[s.second].push_back(s.first);
                }
                else{
                    mp[s.second]={s.first};
                }
            }
            // v.push_back(vec);
            
        }
        for(auto k:mp){
            v.push_back(k.second);
        }
        return v;
    }
};