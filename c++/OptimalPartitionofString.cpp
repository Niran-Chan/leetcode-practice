class Solution {
public:
    int partitionString(string s) {
        /*
            We can use a greedy approach
        */
        vector<int> visited(26,-1);
        int l = 0,ans =0; //left range of current partition
        for(int i =0; i < s.size();++i)
        {
            if(visited[s[i] - 'a'] >= l)
                {
                    ans++;
                    l = i;
                }
            visited[s[i] - 'a'] = i;
        }
        
        return ans + 1;

    }
};
