import java.util.HashMap;
import java.util.Arrays;

public  class TwoSum{
	public static void main(String[] args){
		
		int[] nums = {2,7,11,15};
		int target = 9;
		int[] res = twoSum(nums,target);
		System.out.println(Arrays.toString(res));
	}
//HashMap Implementation
	
    public static int[] twoSum(int[] nums, int target) {
        
    	HashMap<Integer,Integer> map = new HashMap <Integer,Integer>(); //Initialise hashmap
    	
    	for(int i =0;i < nums.length;i++)
    	{
    		if(map.containsKey(target - nums[i]))
    			{
    				int toReturn[] = {(map.get(target - nums[i])),i};
    				return toReturn;
    			}
    		else
    			map.put(nums[i],i);

    	}

    	return null;
    } 

