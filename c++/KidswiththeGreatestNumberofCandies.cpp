class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        //First find the greatest number. Then,iterate through again and see if it beats the maximum
        vector<bool> res(candies.size(),false);
        int mx =0;
        for(int &candy : candies)
            mx = max(mx,candy);
        for(int i =0; i < candies.size();++i)
            res[i] = candies[i] + extraCandies >= mx;
        return res;
        
    }
};
