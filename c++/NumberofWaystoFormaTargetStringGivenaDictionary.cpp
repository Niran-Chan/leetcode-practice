class Solution {
public:
    long long dp [1001][1001];
    int MOD = 1000000007;
    
    int solve(int i,int j,string& target,vector<vector<long long >> &availableChars,vector<string> &words){
        if (j>=target.size())
            return 1;
        if (i>=words[0].size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j] % MOD;
        
        long long inc = 0 , exc = 0;
        if (availableChars[i][target[j]-'a'] != 0)
            inc = ( (availableChars[i][target[j]-'a'] % MOD)*(solve(i+1,j+1,target,availableChars,words) % MOD));
        
        exc = solve(i + 1,j,target,availableChars,words) ;
        return dp[i][j]=(inc+exc) % MOD;

    }
    int numWays(vector<string>& words, string target) {
        //DP problem
        int n = words.size(),m = words[0].size();
        memset(dp,-1,sizeof(dp));
        vector<vector<long long >> availableChars(m,vector<long long>(26,0));
        for(int i =0; i < n;++i){
            for(int j =0; j < m ;++j)
                availableChars[j][words[i][j] - 'a']++;
        }
        //Let i be the pointer to show which index we have to move to, j be the target string index
        //For each word up till the current character index, the character is available
        return solve(0,0,target,availableChars,words);
    }
};
