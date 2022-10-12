#include <bits/stdc++.h>

using namespace std;
//Bottom-up Approach 
  int climbStairs(int n) {
       if(n == 1 || n== 2)
           return n;
        
        int a = 1,b = 2,sum;
        for(int i =2 ; i < n;i++)
        {
            sum = a + b;
            a = b;
            b = sum;
        }
        return sum;
    };

 int main ()
 {
 	int n =5;
 	int res = climbStairs(5);
 	cout << res << endl;
 	return 0;
 }