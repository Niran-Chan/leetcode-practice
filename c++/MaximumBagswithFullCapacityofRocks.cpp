class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int 
additionalRocks) {
        //Always fill up the bags with the least difference in capacity 
and current number of rocks
        //minheap and subtract from the additional rocks
        priority_queue<int,vector<int>,greater<int>> pq;
        for (int i =0 ; i < capacity.size();++i)
            pq.push(capacity[i] - rocks[i]);
        int ans = 0;
        while(additionalRocks && !pq.empty()){
            int currDiff = pq.top();
            pq.pop();
            if(additionalRocks - currDiff >=0)
                additionalRocks -= currDiff;
            else
                break;
            ans ++;
        }
        return ans;

    }
};
