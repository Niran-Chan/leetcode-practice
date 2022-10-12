//Optimised Fibonacci Code! Also applicable for Tribonacci sequence!
#include <iostream>

using namespace std;

int fib (int n)
{
	 if(n < 2) 
            return n;
    	int a = 0, b = 1, c = 0;
        for(int i = 1; i < n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
};

int trib(int n )
{
        if (n == 2)
            return 1;
        if (n < 3)
            return n;
        int a = 0,b = 1,c = 1,d = 0;
        
        for(int i = 2;i < n;i++ )
        {
            d = a + b + c;
            a=b;
            b =c;
            c = d;
        }
        return d;

};

int main ()
{
	int n = 4;
	cout <<"Fibonacci : \t" <<  fib(n) << endl;
    cout << "Tribonacci : \t" << trib(n) << endl;
	return 0;

}