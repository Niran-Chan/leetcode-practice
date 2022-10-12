#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int a,b,c,d;
    bool helper(int i , vector<int>& matchsticks)
    {
        if(i == matchsticks.size())
            return (a==b==c==d && d == 0);
        if(a-matchsticks[i] >=0)
        {
            a -= matchsticks[i];
            bool x = helper(i+1,matchsticks);
            if (x) return true;
            a+= matchsticks[i];
                    
        }
        if(b-matchsticks[i] >=0)
        {
            b-= matchsticks[i];
            bool x = helper(i+1,matchsticks);
            if (x) return true;
            b+= matchsticks[i];
        }
            if(c-matchsticks[i] >= 0 )
            {
                c-=matchsticks[i];
                  bool x = helper(i+1,matchsticks);
            if (x) return true;
                c+=matchsticks[i];
            }
                if(d-matchsticks[i] >= 0)
                {
                    d-=matchsticks[i];
                      bool x = helper(i+1,matchsticks);
                    if (x) return true;
                    d+= matchsticks[i];
                }
        return false;
        
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum % 4 || matchsticks.size() < 4) return false; 
        sum /= 4;
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        
        a = sum,b = sum,c = sum,d = sum;
        return helper(0,matchsticks);
        
    }
};


int main ()
{
	Solution obj;
		
	cout << obj.makesquare({3,3,3,4}) << endl;
return 0;

}
