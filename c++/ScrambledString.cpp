class Solution {
public:

    bool dfs(string s1,string s2,unordered_map<string,bool>& dp){
    //cout << "s1: " << s1 << "\ts2: " << s2 << endl;
    if(s1 == s2)
        return true;
    int n = s1.size();
    if(n != s2.size())
        return false;
    if(n == 1)
        return false;
    string key = s1+s2;
    if(dp.find(key)!=dp.end())
        return dp[key];
    //We try without swap first
    //Meaning we split the string and we divide and conquer the string within
    for(int i =1; i < n;++i){
        bool res1 = (dfs(s1.substr(0,i),s2.substr(0,i),dp) && dfs(s1.substr(i),s2.substr(i),dp));
        if(res1)
            return dp[key] = true;
        bool res2 = dfs(s1.substr(0,i),s2.substr(n-i),dp) && dfs(s1.substr(i),s2.substr(0,n-i),dp);
        if(res2)
            return dp[key] = true;
    }
    return dp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        //1. Select a part of the string to cut and swap or just send the current string down
        if(s1.size() == 1)
            return s1 == s2;
        unordered_map <string,bool> dp;
        return dfs(s1,s2,dp);
    }
};
