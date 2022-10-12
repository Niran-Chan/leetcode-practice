class Solution {
    String ans="";
    public String tree2str(TreeNode root) {
        pass(root);
        return ans;
    }
    public void pass(TreeNode root){
        if(root.left==null&&root.right==null){
            ans+=root.val;
            return;}
        ans+=root.val;
        if(root.left!=null){ans+="(";pass(root.left);ans+=")";}
         if(root.left==null&&root.right!=null){ans+="()";}
        if(root.right!=null){ans+="(";pass(root.right);ans+=")";}
       
    }
}
