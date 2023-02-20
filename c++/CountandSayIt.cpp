class Solution {
public:


    string solve(int n,string s)
    {
        if(n==1)
        {
        return s;
        
        }
       string tmp = "";
       int i =0,j;
        while(i<s.size()) {
            j=i;
        while(i<s.size() && s[i]==s[j]) i++; //find the next non-similiar character and until then, keep incrementing
        
        tmp += to_string(i-j) + s[j]; //freq of character + actual character
    }
        return solve(n-1,tmp);
    }

    string countAndSay(int n) {
    
        string s = "1";
        return solve(n,s);
    }
};