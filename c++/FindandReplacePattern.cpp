class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        //we map each letter of the pattern to the current string value and we observe if the mapping makes sense
        vector<string>res ;
        for(int i =0;i < words.size();i++)
        {
            if(words[i].size() != pattern.size())
                continue;
            unordered_map<char,char> mp1,mp2; //mp1 is pattern char to word char, mp2 is word char to pattern char
            int count = 0;
            for(int j =0; j < words[i].size();j++)
            {
                if(mp1.find(pattern[j]) != mp1.end() || mp2.find(words[i][j]) != mp2.end()) //key exists
                {
                    //if character initially mapped is correct
                    if(mp1[pattern[j]] != words[i][j] || mp2[words[i][j]] != pattern[j])
                        break;
                }
                else 
                {
                    mp1[pattern[j]] = words[i][j];
                    mp2[words[i][j]] = pattern[j];
                }
                count++;
                
            }
            if (count == pattern.size())
                res.push_back(words[i]);
           // cout << count << endl;
        }
        return res;
    }
};
