class Solution {
public:
    int binarySearch(int l,int r,int i,long long success,vector<int>&spells,vector<int> &potions){
        if(l >= r)
            return l;
        int m = int((l+r)/2);
        long long curr = (long long)((long long )potions[m] * (long long )spells[i]);
        if(curr >= success)
            return binarySearch(l,m,i,success,spells,potions);
        else
            return binarySearch(m+1,r,i,success,spells,potions);
        
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        //Bigger spell determines range of potions first
        //Conduct binary search for the next range and so on
        vector<int> ans;
        for(int i = 0 ; i < spells.size();++i){
            int l = binarySearch(0,potions.size(),i,success,spells,potions);
            ans.push_back(potions.size() - l);
        }
        return ans;
    }
};
