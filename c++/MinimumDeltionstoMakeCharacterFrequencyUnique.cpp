#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int minDeletions(string s) {
        vector <int> v(26,{0});
        for(int i =0 ; i < s.size();i++)
        {
            v[s[i]-'a']++;
        }
        sort(v.begin(),v.end());
        int res = 0,f=v[v.size()-1];
        for(int x=25; x >= 0;x--)
        
        {
            //No more frequency can be handled so we delete wtv remaining characters
            if(f<0)
                {
                if(v[x] ==0 ) break;
                    res += v[x];
            }
            //If number greater than freq
            else if(v[x] > f)
                res += v[x] - f;
            else if (v[x] < f)
                f = v[x];
            f--;
        }
            return res;
            
            
    }
};


int main ()
{
    Solution soln = Solution();
    string s =  "bbcebab"; 
    cout << soln.minDeletions(s) << endl;
    return 0;


}
