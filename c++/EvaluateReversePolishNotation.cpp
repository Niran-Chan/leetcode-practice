class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <long long > operands;
        for(auto token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == 
"/"){
                long long  a = operands.top();
                operands.pop();
                long long b = operands.top();
                operands.pop();
                if(token == "+")
                    operands.push(b + a);
                else if (token == "-")
                    operands.push(b - a);
                else if (token =="*")
                    operands.push(b * a);
                else
                    operands.push(b / a);
            }
            else
                operands.push(stoi(token));
        }
        return operands.top();

    }
};
