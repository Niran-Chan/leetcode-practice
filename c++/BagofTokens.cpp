class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0,l=0,r=tokens.size()-1;
        sort(tokens.begin(),tokens.end());
        while(l<=r)
        {
            if(l <=r && power - tokens[l] >=0)
            {
                power-=tokens[l];
                l++;
                score++;
            }
            else if(l<r && score > 0 && power-tokens[l] <0 )
            {
                power+= tokens[r];
                r--;
                score--;
            }
            else break;
            
        }
        return score;
    }
};
