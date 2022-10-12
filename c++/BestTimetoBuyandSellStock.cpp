#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    int maxProfit(vector<int>& prices) {
   	//Use Kadane's Algorithm
    int max_profit=0,local_max=0,difference=0;
    	for(int i =1;i < prices.size();i++){
   	 		difference = prices[i] - prices[i-1];
   		 	local_max = max(0,local_max + difference );
   		 	max_profit = max(local_max,max_profit);
    	}
    	return max_profit;

    }
};



int main()
{
	Solution result;
	vector <int> prices = {2,1,2,0,1};
	cout << result.maxProfit(prices);



}