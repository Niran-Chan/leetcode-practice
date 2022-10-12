import java.util.*;

public class JumpGameVI
{

	public static void main (String[] args)
	{
		int[] nums= {1,-1,-2,4,-7,3};
		int k = 2;
		int res = maxResult(nums,k);
		System.out.println(res);
	}


	public static int maxResult(int[] nums, int k)
	{
		 Queue <Pair<Integer,Integer> > testStringsPQ = new PriorityQueue<Pair<Integer,Integer>>(nums.size(),Comparator.comparing(Pair::getKey));
			
		 return 0;

	}



}


