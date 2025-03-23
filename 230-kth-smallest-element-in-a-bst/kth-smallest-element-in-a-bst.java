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
    public int kthSmallest(TreeNode root, int k) {
        if(root==null) return 0;
        Stack<TreeNode>st=new Stack<>();
        while(!st.empty() || root!=null){
            while(root!=null){
                st.push(root);
                root=root.left;
            }
            TreeNode top=st.peek();
            st.pop();
            if(--k==0) return top.val;
            root=top.right;
        }
        return -1;
    }
}