#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 void recursiveCheck(vector<int>&candidates, const int target, vector<vector<int>>& res,vector<int>& comb, int i)
    {
        if (target == 0)
        {
            res.push_back(comb);
            return;
        }
        while(i < candidates.size() && target-candidates[i] >=0)
        {
            comb.push_back(candidates[i]);
            recursiveCheck(candidates,target-candidates[i],res,comb,i);
            i++;
            comb.pop_back();
            
            
        }
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //We can make a recursive function 
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector <int> comb;
        recursiveCheck(candidates,target,res,comb,0);
        return res;
        
    
    };

 int main ()
 {
 	vector <int> candidates = {2,3,6,7};
 	int target = 7;
 	vector <vector <int>> res = combinationSum(candidates,target);
 	cout << "[" ;
 	for (auto x : res)
 	{
 		cout << "[";
 		for(auto y : x)
 			cout << y <<",";
 		cout << "]" ;

 	}
 	cout << "]";

 	return 0;
 }