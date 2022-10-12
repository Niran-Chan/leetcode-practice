import java.util.*;


public  class CombinationSum{

	public static void main (String[] args )
	{
		List<List<Integer>> fin = new ArrayList<List<Integer>>();
		int[] candidates = {2,3,5};
		int target= 8;
		fin = combinationSum(candidates,target);
		for(int i =0;i < fin.size();i++)
		{
			System.out.println("[");
				System.out.println("," + fin.get(x));
			System.out.println("]");
		}
	}
    
    public static void recursiveLoop(int[] candidates,int target,List<List<Integer>> res,int i,List<Integer> comb)
    {
    	if(target == 0)
    	{
    		res.add(new ArrayList<>(comb));
    		return;
    	}
    	while(i < candidates.length && target - candidates[i] <= 0)
    	{
    		comb.add(candidates[i]);
    		recursiveLoop(candidates,target,res,i,comb);
    		i++;
    		comb.remove(comb.size() - 1);

    	}    
    }
    
    
    
    
    
    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
      List<List<Integer>> res = new ArrayList<List<Integer>>();
    	List<Integer> comb = new ArrayList<Integer>() ;
    recursiveLoop(candidates,target,res,0,comb);
       
       return res;
        
        
    }

}
