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
void getPath(TreeNode* root, vector<string>& path, string& st){
        if(!root) return;
        if(!root->left && !root->right) path.push_back(st);
        if(root->left){
            st += 'l';
            getPath(root->left,path,st);
            st.pop_back();
        }
        if(root->right){
            st += 'r';
            getPath(root->right,path,st);
            st.pop_back();
        }
    }
    // void dfs(TreeNode* root, vector<int>&leaf_nodes, vector<int>&inorder){
    //     if(root==NULL) return;
    //     if(root->left==NULL && root->right==NULL) leaf_nodes.push_back(root->val);
    //     dfs(root->left,leaf_nodes,inorder);
    //     inorder.push_back(root->val);
    //     dfs(root->right,leaf_nodes,inorder);
    // }
    int countPairs(TreeNode* root, int distance) {
        // vector<int>leaf_nodes;
        // vector<int>inorder;
        // dfs(root,leaf_nodes,inorder);
        // int count=0;
        // unordered_map<int,int>mp;
        //     for(int i=0;i<inorder.size();++i){
        //         mp[inorder[i]]=i;
        //     }
        //     for(int i=0;i<leaf_nodes.size();++i){
        //     for(int j=i+1;j<leaf_nodes.size();++j){
        //         if((mp[leaf_nodes[j]]-mp[leaf_nodes[i]])<=distance){
        //             count+=1;
        //         }
        //         else{
        //             break;
        //         }
        //     }
        //     }
        //     return count;

        int ans = 0;
        vector<string>path;
        string st = "";
        getPath(root, path, st);
        for(int i = 0; i < path.size(); i++){
            for(int j = i + 1; j < path.size(); j++){
                int k = 0;
                int tmp = 0;
                while(k < path[i].size() && k < path[j].size()){
                    if(path[i][k] != path[j][k]) break;
                    k++;
                }
                tmp += path[i].size() - k + path[j].size() - k;
                if(tmp <= distance) ans++;
            }
        }
        return ans;

    }
};