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
    public List<List<Integer>>res=new ArrayList<>();
    public void dfs(TreeNode root, int sum, List<Integer>row, int targetSum){
        if(root==null) return;
        sum+=root.val;
        row.add(root.val);
        if(root.left==null && root.right==null && sum==targetSum){
            res.add(new ArrayList<>(row));
        }
        dfs(root.left,sum,row,targetSum);
        dfs(root.right,sum,row,targetSum);
        row.remove(row.size() - 1);
    }
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        if(root==null) return res;
        int sum=0;
        List<Integer>row=new ArrayList<>();
        dfs(root,sum,row,targetSum);
        return res;
    }
}