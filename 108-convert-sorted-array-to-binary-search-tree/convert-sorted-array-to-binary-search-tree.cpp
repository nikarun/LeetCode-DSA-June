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
    TreeNode *constructTree(vector<int>&nums, int start, int end){
        if(start>end) return NULL;
        int mid=start+(end-start)/2;
        int val=nums[mid];
        TreeNode *ptr=new TreeNode(val);
        ptr->left=constructTree(nums,start,mid-1);
        ptr->right=constructTree(nums,mid+1,end);
        return ptr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return NULL;
        return constructTree(nums,0,n-1);
    }
};