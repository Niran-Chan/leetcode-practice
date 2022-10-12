/*
 * Given an integer array nums, find number of distinct contiguous subarrays with at most k odd elements. 
 * Two subarrays are distinct when they have at least one different element.
 * 
 */
import java.util.*;


public class DistinctSubarrayswithatmostkoddelements
{
    private void printTwoDArray(ArrayList<ArrayList<Integer>> arr)
    {
        System.out.print("[");
        for(int r =0 ; r < arr.size();r++){
            System.out.print("[");
            for(int j =0; j < arr.get(r).size();j++)
                System.out.print( arr.get(r).get(j) + ",");
            System.out.print("]");

            }
        System.out.print("]");
        System.out.println();
    }

    private int dfs(int i,int k,int nums [],int dp [][],ArrayList<ArrayList<Integer>> arr,ArrayList<Integer> backTrackArr)
    {
        if(k == 0)
        {

            arr.add(backTrackArr);
            return 1;
        }
        if(dp[k][i] != -1 )
            return dp[k][i];
        
        int cnt = 0;
     

        for(int r = i;r < nums.length;r++)
            {
                //Backtracking
               
                backTrackArr.add(nums[i]);
                cnt += dfs(r,k-1,nums,dp,arr,backTrackArr);
                backTrackArr.remove(backTrackArr.size()-1);
            }
        return dp[k][i] = cnt;
        
    }

    private void fillArray(int A[][]){
        for(int r =0 ;r < A.length;r++)
            for(int c = 0; c < A[0].length;c++)
                A[r][c] = -1;

    }

    private boolean checkDuplicates( ArrayList<Integer> A,ArrayList<ArrayList<Integer>> B)
    {

        //Compare duplicates for all existing arrays      
        
        return false;

    }

    private void solve(int []nums,int k)
    {
       

        int dp [][] = new int [k][nums.length]; //Column number
        this.fillArray(dp);
        int ans = 0;
        ArrayList<ArrayList<Integer>> allComb = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> backTrackArr = new ArrayList<Integer>();
        for(int i = 0; i < k;i ++){
      
            ans += dfs(0,i,nums,dp,allComb,backTrackArr); //different values of k
        }
        printTwoDArray(allComb);
        System.out.println(ans);
        return;
    }
    public static void main (String[] args)
    {
        int nums [] = {1,3,9,5}; //Test Case
        int k = 2;

        DistinctSubarrayswithatmostkoddelements Solution = new DistinctSubarrayswithatmostkoddelements();

        Solution.solve(nums,k);
        return;
    
    }
}
