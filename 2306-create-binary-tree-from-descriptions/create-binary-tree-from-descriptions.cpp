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
    // int find_root(vector<vector<int>>& descriptions){
    //     unordered_map<int,int>mp;
    //     for(int i=0;i<descriptions.size();++i){
    //         mp[descriptions[i][1]]=1;
    //     }
    //     for(int i=0;i<descriptions.size();++i){
    //         if(mp.find(descriptions[i][0])==mp.end()){
    //             return descriptions[i][0];
    //         }
    //     }
    //     return -1;
    // }
    // TreeNode *create_tree(unordered_map<int,pair<int,int>>mp, int root){
    //     TreeNode *ptr=new TreeNode(root);
    //     if(mp.find(root)==mp.end()) return ptr;
    //     if(mp[root].first!=-1){
    //         // cout<<"first "<<mp[root].first<<endl;
    //         ptr->left=create_tree(mp,mp[root].first);
    //     }
    //     if(mp[root].second!=-1){
    //         // cout<<"second "<<mp[root].second<<endl;
    //         ptr->right=create_tree(mp,mp[root].second);
    //     }
    //     return ptr;
    // }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // unordered_map<int,pair<int,int>>mp;
        // // int root=-1;
        // int root=find_root(descriptions);
        // // cout<<"root "<<root<<endl;
        // for(int i=0;i<descriptions.size();++i){
        //     if(mp.find(descriptions[i][0])!=mp.end()){
        //         if(descriptions[i][2]==0){
        //             pair<int,int>p=mp[descriptions[i][0]];
        //             mp[descriptions[i][0]]={p.first,descriptions[i][1]};
        //         }
        //         else{
        //             pair<int,int>p=mp[descriptions[i][0]];
        //             mp[descriptions[i][0]]={descriptions[i][1],p.second};
        //         }
        //     }
        //     else{
        //         if(descriptions[i][2]==0){
        //             mp[descriptions[i][0]]={-1,descriptions[i][1]};
        //         }
        //         else{
        //             mp[descriptions[i][0]]={descriptions[i][1],-1};
        //         }
        //     }
        // }
        // return create_tree(mp,root);
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>children;
        for(auto &desc:descriptions){
            int parent = desc[0];
            int child=desc[1];
            bool is_left=desc[2]==1;
            children.insert(child);
            if(mp.find(parent)==mp.end()){
                mp[parent]=new TreeNode(parent);
            }
            if(mp.find(child)==mp.end()){
                mp[child]=new TreeNode(child);
            }
            if(is_left){
                mp[parent]->left=mp[child];
            }
            else{
                mp[parent]->right=mp[child];
            }
        }
        int root=-1;
        for(auto &desc:descriptions){
            if(children.find(desc[0])==children.end()){
                root=desc[0];
                break;
            }
        }
        return mp[root];
    }
};


// mp[20]={15,17}
// mp[50]={20,80}
// mp[80]={19,-1}
