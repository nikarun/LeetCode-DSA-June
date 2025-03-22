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
    public int maxSum=-10000;
    public int pathSum(TreeNode root){
        if(root==null) return 0;
        int leftSum=pathSum(root.left);
        int rightSum=pathSum(root.right);
        if(leftSum<0) leftSum=0;
        if(rightSum<0) rightSum=0;
        maxSum=Math.max(maxSum,leftSum+rightSum+root.val);
        return Math.max(leftSum,rightSum)+root.val;
    }
    public int maxPathSum(TreeNode root) {
        if(root==null) return 0;
        pathSum(root);
        return maxSum;

    }
}