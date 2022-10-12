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
    public List<Integer> inorderTraversal(TreeNode root) {
        //Traverse from left sub tree to right subtree to root
            ArrayList v = new ArrayList<Integer>();
            TreeNode cur = root;
            while(cur != null)
            {
                if(cur.left == null)
                {
                    v.add(cur.val);
                    cur = cur.right;
                }
                else
                {
                    TreeNode prev = cur.left;
                    while(prev.right!= null && prev.right != cur)
                            prev = prev.right; //Traverse to right mot child of left subtree
                    
                    if(prev.right == cur) //sub tree has already been visited to move our cur
                    {
                        prev.right = null;
                         v.add(cur.val);
                        cur = cur.right;
                       
                    }
                    else
                    {
                        prev.right = cur;
                        cur = cur.left;
                        
                    }                //Sub tree has not been traversed
                    
                    
                }

            }
        return v;
    }
}
