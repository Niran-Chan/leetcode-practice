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

    private void solve(TreeNode root,int val, int n)
    {
        if(root == null)
            return;
        if(n == 1)
           {
              TreeNode newLeft=new TreeNode(val);
              TreeNode newRight=new TreeNode(val);
              newLeft.left=root.left;
              newRight.right=root.right;
              root.left=newLeft;
              root.right=newRight;
           } 
            solve(root.left,val,n-1);
            solve(root.right,val,n-1);

           return;
        

    }

    public TreeNode addOneRow(TreeNode root, int val, int depth) {
            //edge cases
            if(depth == 1)
            {
                TreeNode newNode=new TreeNode(val,root,null);
                root = newNode;
                return root;
            }
            solve(root,val,depth - 1);
            return root;
    }
}