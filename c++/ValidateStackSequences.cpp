class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        //Iterate through and check if element can be popped
        stack <int> curr;
        int j =0; 
        for(int i =0; i < pushed.size();++i){
            curr.push(pushed[i]);
            while(!curr.empty() && popped[j] == curr.top())
                {curr.pop();++j;}
    
        }
        for(;j < popped.size();++j){
            if(curr.empty() || popped[j] != curr.top())
                return false;
            curr.pop();
        }
        return true;
        
    }
};
