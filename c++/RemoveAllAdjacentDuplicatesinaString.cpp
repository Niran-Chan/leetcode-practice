class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        stack<char> stk;
        for(int i = s.size()-1; i >=0;--i){
          
            if(!stk.empty()){
                if(stk.top() == s[i]){
                    stk.pop();
                }
                else
                    {
                        stk.push(s[i]);
                    }
            }

            else
                stk.push(s[i]);

        }
        while(!stk.empty())
            {
                res += stk.top();
                stk.pop();
            }
        return res;
    }
};
