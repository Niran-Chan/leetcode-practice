class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        Arrays.sort(tokens);
        //we always face down the tokens with the higher power so we can get higher power
        int score = 0;
        int l = 0, r = tokens.length - 1 ;
        while(l<=r)
        {
            //only take power of largest token when we can no longer face up the token

            while( l<=r && (power - tokens[l]) >= 0 )
                {
                    power -= tokens[l];
                    l++;
                    score++;
                }
          if(l<r && score >= 1 && (power - tokens[l]) <= 0)
          {

                power += tokens[r];
                r--;
                score--;
                System.out.println(score);
          }
            else break;
         
        }
        
        return score;
    }
}
