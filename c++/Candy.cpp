#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
    if(n == 1) return 1;
    vector<int> candies(n,1);
    //Populate an array for the candies allocated based on the first iteration forwards
    for(int i=1; i<n; i++)
    {
        if(ratings[i] >ratings[i-1])
        {
            candies[i]+=candies[i-1];
        }
    }
//Iterate backwards to cross check with the candies if they have been allocated correctly with their next neighbour
    for(int i=n-2; i>-1; i--)
    {
        if(ratings[i] > ratings[i+1])
        {
            if(candies[i] > candies[i+1]) continue;
            candies[i] = max(candies[i], candies[i+1])+1;
        }
    }

    int sum = 0;
    for(auto x: candies)
    {
        sum+=x;
    }
    return sum;
    }
};

int main ()
{
	Solution obj;
	vector <int> ratings {1,2,1};	
	cout << obj.candy(ratings) << endl;
	return 0;


}
