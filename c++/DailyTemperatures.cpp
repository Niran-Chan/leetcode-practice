class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //number of times we pop = number of days
        stack <int> stk;
        vector<int> res(temperatures.size());
        for(int i =0; i < temperatures.size();++i){
            int a = temperatures[i];
            while(!stk.empty() && a > temperatures[stk.top()]){
                    res[stk.top()] = i - stk.top();
                    stk.pop();
                }
                stk.push(i);
            }
        return res;
    }
};

