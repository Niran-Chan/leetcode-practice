#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        //Two pointers solution
        //start and end of string
        int head = 0, tail = s.size()-1;
        while(head<tail)
        {
            if(!isalnum(s[head])){head++;continue;}
            if (!isalnum(s[tail])){tail--;continue;}
            if(tolower(s[head]) == tolower(s[tail]))
            {head++;tail--;}
            else    
                return false;
       
        }
        return true;
    }
};


int main ()
{
	Solution obj;
	string s = "A man, a plan, a canal: Panama" ;
	cout << obj.isPalindrome(s);
	return 0;
}