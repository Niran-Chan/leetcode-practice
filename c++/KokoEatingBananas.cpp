class Solution {
public:
    bool check(int k,vector<int>& piles,int h){
           for(int i=0;i<piles.size();i++)
        {
            if(piles[i]%k==0)
                h-=(piles[i]/k);//(piles[i]/speed) units of time to finish pile
            else
                h-=(piles[i]/k)+1;
            if(h<0)
                return false;
        }
        return true;//Guards didn't return wihtin time to catch
        };
    int minEatingSpeed(vector<int>& piles, int h) {
        //Determine eating speed
        //range of eating values
        //binary search to determine the correct range to which koko can finish
        //maximum range is the maximum value in the piles 
        //minimum is the minimum in the pile
        //check function that can check if we are able to finish within h
            int l = 1,r = INT_MIN;

            for(int &a : piles){
                r = max(r,a);
            }
            int k = r;
            while(l < r){
                int m  =  (l + r)/2;
                if(check(m, piles,h)) 
                    {
                        r = m;
                    }
                else
                    l = m + 1;
            }
            return r;
        }
};
