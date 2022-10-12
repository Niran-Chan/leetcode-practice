public class FibonacciNumber{
	public static void main (String[] args){
		int n = 3;
		int res = fib(n);
		System.out.println(res);

	}
	//Easy recursive function
	 /*
	 public static int fib(int n) {
	 	if (n==0)
	 		return 0;
	 	if(n == 1)
	 		return n;
	 	return fib(n-1) + fib(n-2);
        
    }
    */
    //Iterative method
    //Fastest method

    public static int fib (int n)
    {
    	if(n <= 1)
    		return n;
    	int a = 0, b = 1,sum = 0;
    	while (n > 0)
    	{
    		 sum = a + b;
    		a = b;
    		b = sum;
    		n--;

    	}
    	return a;



    }

}