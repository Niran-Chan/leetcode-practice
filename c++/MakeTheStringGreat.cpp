class Solution {
public:

    bool isUpper(char &a,char &b){

        if(isupper(a) && a + 32 == b || isupper(b) && b + 32 == a){
            return true;
        }
        return false;
    }
    string printStk(stack <char> &stk){
        string res = "";
        while(!stk.empty()){
            res += stk.top();
            stk.pop();}
        return res;
    }
    string makeGood(string s) {
        //if uppercase version of character exists then remove both the current character and the upper case character
        int i {0};
        int n = s.size();
        stack <char> stk;
        stk.push(s[n-1]);
        for(int i = n-2; i >= 0;--i){

            if(!stk.empty() && isUpper(stk.top(),s[i]))
                    stk.pop();
            else
                stk.push(s[i]);
        }
        
        return printStk(stk);
    }       
};
