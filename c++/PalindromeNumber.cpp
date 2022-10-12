#include <iostream>

using namespace std;

/*
bool isPalindrome(int x)
{

//Two pointers can solve it. Read from end of number and from start of number
        string t=to_string(x);
        
        for(int i =0; i < t.size()/2;i++)
        {
          char a = t[i],b = t[t.size()-i-1] ;
        if(a!=b)
            return false;
        }
    return true;

};

*/
//Integer solution and much faster

bool isPalindrome(int x) {
        
        long long int y =0,n = x,final = x;
        
        //logic without converting to string
        if(x < 0)
            return false;
        
        while(n > 0){
           
            y= y*10 + n%10 ; 
             n =  n/10;
           
            }
        return (y == final);
        };

int main ()
{
	int test = 1001;
	bool result = isPalindrome(test);
	cout << result << endl;
	return result;

}