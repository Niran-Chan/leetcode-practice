class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        //Create pairs of ages and scores, and sort by age
        int n = scores.size();
        vector<pair<int,int>> players;
        for(int i =0; i < n;++i){
            players.push_back({ages[i],scores[i]}); //{age,score}
        }
        sort(players.begin(),players.end());
        //Now sorted by age, we know that any score higher than current 
number means we are f-ed
        vector<int> dp(n);
        int maxScore = 0;

        for(int i =0; i < n;++i){
            dp[i] = players[i].second;
            for(int j = 0; j < i;++j){
                if(players[j].second <= players[i].second)
                    {
                        dp[i] = max(dp[i],dp[j] + players[i].second); 
//Current node is higher, or the sum of the previous node with the current 
node?
                    }
            }
            maxScore = max(dp[i],maxScore);
        }

        return maxScore;
    }
};
