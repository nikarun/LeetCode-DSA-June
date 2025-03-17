/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isValid=true;
    public boolean dfs(TreeNode root, TreeNode lower, TreeNode upper){
        if(root==null) return true;
        if(lower!=null){
            if(root.val<=lower.val) return false;
        }
        if(upper!=null){
            if(root.val>=upper.val) return false;
        }
        return dfs(root.left,lower,root) && dfs(root.right,root,upper);
    }
    public boolean isValidBST(TreeNode root) {
        if(root==null) return true;
        return dfs(root,null,null);
        
    }
}