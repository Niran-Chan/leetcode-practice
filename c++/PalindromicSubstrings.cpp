//Mathematical Way
class Solution {
public:
    int countSubstrings(string S) {
        int len = S.length(), ans = 0;
        int i =0;
        while(i < len) {
            int j = i - 1, k = i; //The two pointers to spread outwatds
            while (k < len - 1 && S[k] == S[k+1]) 
                k++; //Right ptr search
            ans += (k - j) * (k - j + 1) / 2, i = k++; //All the same 
characters reduced and they are all palindromes on the right side
            //Triangular Number Calculation
            
            while (~j && k < len && S[k++] == S[j--])  //~ is a bitwise 
NOT operator(0 and -1) so, while j >= 0
                ans++; //palindrome on the left side
            i++;
        }
        return ans;
    }
};

//Naive Way

class Solution {
public:
    int countSubstrings(string s){
        int n=s.size();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){
                    dp[i][j]=1;
                    ans++;
                }
                else if(gap == 1 and s[i]==s[j]){
                    dp[i][j]=1;
                    ans++;
                }else if(s[i] == s[j] and dp[i+1][j-1] ==1){
                    dp[i][j]=1;
                    ans++;
                }
            }
        }
        return ans;
    }
};
