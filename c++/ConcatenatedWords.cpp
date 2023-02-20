class Solution {
public:


    bool dfs(string s,set<string> &substrExists){
        for(int i =1; i < s.size()+1;++i){
            string s1=s.substr(0,i); //see if we can find this substring 
or not
            string s2 = s.substr(i);
            if(substrExists.count(s1) && (substrExists.count(s2) || 
dfs(s2,substrExists)))
            {
                substrExists.insert(s2);
                return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
{
        //Generate a list of possible combinations that will allow us to 
get the final string value
        set <string> substrExists(words.begin(),words.end());
        vector<string> ans;
        for(auto word : words)
            {
                if(dfs(word,substrExists))
                    ans.push_back(word);
            
            }
        return ans;
    
    }
};
