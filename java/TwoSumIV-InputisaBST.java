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

    private void formList (TreeNode root,ArrayList<Integer> mp)
    {
        if(root == null)
            return;

        formList(root.left,mp);
        mp.add(root.val);
        formList(root.right,mp);
    }
    public boolean findTarget(TreeNode root, int k) {
        ArrayList<Integer> mp = new ArrayList<Integer>();
        formList(root,mp);
        int l =0, r= mp.size() - 1;
        while( l < r)
         {
             int sum = mp.get(l) + mp.get(r);
            if(sum == k)
                return true;
            if(sum < k)
                l++;
            else
                r--;
         }
         return false;
    }
}