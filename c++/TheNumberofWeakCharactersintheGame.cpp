class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        sort(prop.begin(),prop.end(),comp); //Sort each element by attack 
from low to high and greatest defense from high to low 
        
        int maxTillNow = INT_MIN;
        int ans=0;
        for(int i=prop.size()-1;i>=0;i--){
            if(prop[i][1]<maxTillNow){
                ans++;
            }
            else 
                maxTillNow = prop[i][1];
        }
        return ans;
    }
};


