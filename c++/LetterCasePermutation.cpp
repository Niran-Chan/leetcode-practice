class Solution {
public:
    
    void helper(int i,int n, string s, string comb ,vector<string>& res)
    {
        if(i == n)
        {res.push_back(comb);return;}
        
       
        if(!isalpha(s[i])){comb += s[i];helper(i+1,n,s,comb,res);}
        else{
        string temp = comb;
        comb += tolower(s[i]);
        helper(i+1,n,s,comb,res);
        comb = temp;

        comb += toupper(s[i]);
        helper(i+1,n,s,comb,res);
        comb =  temp;
        }
        return;
        
        
    }
    
    
    vector<string> letterCasePermutation(string s) {
        //First we need to check if the current char is a letter or a 
numer
        //then we can invoke a back track function with uppercase
        vector <string> res;
        helper(0,s.size(),s,"",res);
        return res;
    }
};
