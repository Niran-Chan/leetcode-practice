#include <iostream>
#include <climits>

using namespace std;
 int reverse(int x) {
       int y = 0;
        
        while(x)
        {
            if(y + (x % 10) / 10 > INT_MAX / 10 || y + (x % 10) / 10 < INT_MIN / 10) return 0; 
            y = (x % 10)  + y*10;
            x /= 10;
        }
        
        return int(y);
    };


  int main ()
  {
  	int x = 123;
  	int res = reverse(x);
  	cout << x << endl;

  	return 0;
  }