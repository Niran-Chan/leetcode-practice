#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    
    int numMatchingSubseq(string s, vector<string>& words) {

        //Hashtable 
        
        int res =0 ;
        unordered_map<string,int> mp;
        for(int i =0;i < words.size();i++)
        {
            if(mp.find(words[i]) != mp.end())
            {res += mp[words[i]];continue;}
             int x = 0,count = 0;
               while(x < words[i].size() && count < s.size())
                {
                    if(words[i][x] == s[count])
                        x++;
                   
                    count++;
                }
                if(x == words[i].size())
                {res++;mp[words[i]]=1;}
                else mp[words[i]] = 0;
        }     
    return res;
      
    }
    
};


int main ()

{
Solution obj;
cout << obj.numMatchingSubseq("abcde",{"a","bb","acd","ace"});

return 0;
}
