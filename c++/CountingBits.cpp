#include <iostream>
#include <vector>

using namespace std;
/*
//Iterative
    int intToBin(int n)
    {
        int a = 0;
        int temp;
        while(n)
        {
            temp = n/2;
            if(n-temp*2)
                a++;
            //Divide by 2 and any remainder is considered a bit 
            n/=2;
            
        }
        return a;
        
    }
    
    
    vector<int> countBits(int n) {
        vector <int> res;
        res.reserve(n+1);
        //Iterate until n
        for(int i =0;i < n+1;i++)
        {
            res.push_back(intToBin(i));
            
        }
        return res;
    };
*/
/*
//Recursion
   int intToBin(int n,int a)
    {
        if(n == 0)
            return a;
        int temp = n/2;
        if(n != temp*2)
            a++;
        n/=2;
        return intToBin(n,a);
        
    }
    
    
    vector<int> countBits(int n) {
        vector <int> res;
        res.reserve(n+1);
        //Iterate until n
        for(int i =0;i < n+1;i++)
        {
            res.push_back(intToBin(i,0));
            
        }
        return res;
    };
*/
//MOST OPTIMAL O(N) METHOD

    vector<int> countBits(int n) {
        
        // n+1 as we are going to count from 0 to n
        vector<int> t(n+1);
        
        // t[0] will be 0 beacuse 0 has count of set bit is 0;
        t[0] = 0;
        
        // we can compute current set bit count using previous count
        // as x/2 in O(1) time
        
        // i%2 will be 0 for even number ans 1 for odd number (for Least Significant Bit)
        int offset = 1;
        for(int i = 1; i<=n; ++i)
            {
            //Observing the algorithm, after every 2**n, the offset changes
            //The number of bits is equivalent to the first set of digits and so, we can just subtract the offset back          
  
            offset = (i == offset *2) ? i : offset;
            cout << "Iteration :"<< i << "\tOffset :" << offset << endl;
            t[i] = 1 + t[i-offset];

            //OR ANOTHER ALGORITHM
            // t[i] = t[i/2] + i%2;
                }
        
        return t;
    };

int main ()

{
	int n = 5;
	vector <int> res=  countBits(n);
	for(auto x : res)
		cout << x << ",";
}