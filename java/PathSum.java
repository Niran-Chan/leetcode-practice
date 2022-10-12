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

    private boolean traverseTree(TreeNode root,int targetSum)
    {

        if(root == null)
            return false;
        targetSum -= root.val;
        //Considered a leaf if no left or right nodes
        if(root.left == null && root.right == null)
            {
                if(targetSum ==0)
                    return true;
                return false;
            }

        return traverseTree(root.left,targetSum) || traverseTree(root.right,targetSum);

    }

    public boolean hasPathSum(TreeNode root, int targetSum) {
        return traverseTree(root,targetSum);
    }
}
