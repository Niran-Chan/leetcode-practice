class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> src(n+1,0);
        vector<int> freq(n+1,0);
        for(auto &a : trust)
            {
                freq[a[1]]++;
                src[a[0]]++;}
        for(int i =1; i < n+1;++i)
            {
                if(freq[i] == n-1 && src[i] == 0)
                    return i;
            }
        
        
        return -1;
    }
};
