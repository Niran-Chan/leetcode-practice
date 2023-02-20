class Solution {
public:
    bool wordPattern(string pattern, string s) {
        //Use a dictionary to check corresponding keys and values
        unordered_map <string,char> wordsmp;
        unordered_map <char,string> chrsmp;
        vector<string> arr = {};
        string tmp = "";
        //Generate string array
        for (int i =0 ; i<s.size();++i){
            if(s[i] == ' ')
                {
                    arr.push_back(tmp);
                    tmp = "";
                }
            else
                tmp += s[i];
        }
        if(tmp != "")
            arr.push_back(tmp);
        
        if(arr.size() != pattern.size())
            return false;

        for(int i =0; i < arr.size();++i){
            //cout << "KEY : " << arr[i] << "\tVAL: " << wordsmp[arr[i]] 
<< "\n";
            if(!wordsmp[arr[i]])
                {
                if(chrsmp[pattern[i]]!="" && chrsmp[pattern[i]] != arr[i])
                    return false;
                wordsmp[arr[i]] = pattern[i];
                chrsmp[pattern[i]] = arr[i];
                }
            else if(wordsmp[arr[i]] != pattern[i])
                return false;
            else
            {
                continue;
            }

        }


        return true;
    }
};
