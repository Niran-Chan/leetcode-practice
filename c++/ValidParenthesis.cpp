class Solution {
public:
    bool isValid(string s) {
        stack <char> stk;
        stk.push(' ');
        for(int i = 0; i < s.size();i++)
        {   
            if (s[i] == ')' && stk.top()=='(' || s[i] == ']' && stk.top() == '[' || s[i] == '}' && stk.top() == '{' ){
                stk.pop();
            }
                else
                    stk.push(s[i]);
    
             
            
        }
        
        if(!stk.empty() && stk.top() != ' ')
            return false;
        return true;
    }
};