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
class PathSumII {
    List<List<Integer>> paths = new ArrayList<List<Integer>>() ;
    
    public void dfs(TreeNode root,List <Integer> arr,int currSum,int targetSum)
    {
        if(root == null)
            return;

        arr.add(root.val);
        currSum += root.val;
        if(root.left == null && root.right == null) //leaf node
        {
            if(currSum == targetSum)
                paths.add(new ArrayList<>(arr));
            arr.remove(arr.size() - 1);
            
            return;
        }
        
        if(root.left != null)
            dfs(root.left,arr,currSum,targetSum);
        if(root.right != null)
            dfs(root.right,arr,currSum,targetSum);
        arr.remove(arr.size() - 1);
        return;
    }
    
    
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        
        dfs(root, new ArrayList<Integer>(),0,targetSum);
        return paths;
    }

    public static void main(String [] args)
    {
        
        return;
    }
}