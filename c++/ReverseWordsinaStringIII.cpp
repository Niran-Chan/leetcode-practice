class Solution {
public:
    string reverseWords(string s) {
        //use stack to store and reverse
        stack <char> stk;
        string res = "";
        for(int i =0 ; i < s.size();i++)
        {
            if(s[i] == ' ')
            {
                while(!stk.empty()) {res+=stk.top();stk.pop();}
                res += ' ';
            }
             else stk.push(s[i]);
            
        }
          while(!stk.empty()) {res+=stk.top();stk.pop();}
        return res;
    }
};
