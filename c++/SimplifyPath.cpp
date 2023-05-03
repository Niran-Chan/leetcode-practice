class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string word = "";

        for(int i =0; i < path.size();++i){
           if(path[i] == '/')
            {
                //cout << "Word: " << word << endl;
                if(word == ".")
                    word = "";
                else if (word == "..")
                    {
                        if(!stk.empty()){
                            //cout << "Popping " << stk.top() << endl;
                            stk.pop();}
                    }
                else if (word != "")
                {
                    //cout << "Pushing " << word << endl;
                    stk.push(word);
                }
                word = "";
            }
            else
                word += path[i];
        }
        if(!word.empty()){
            //We still have one last word
            if(word == ".."){
                    if(!stk.empty())
                        {//cout << "Popping " << stk.top()<<endl;
                            stk.pop();
                        }
                    }
            else if(word != ".")
                stk.push(word);
        }
        string s = "";
        while(!stk.empty())
            {
                s = "/" + stk.top() + s;
                stk.pop();
            }

        if(s.empty())
            return "/";
        return s;
    }
};
