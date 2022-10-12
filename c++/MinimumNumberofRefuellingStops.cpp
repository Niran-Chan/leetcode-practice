class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue <int> pq;
        int currFuel= startFuel;
        int i =0 ;
        int count = 0;
        while(currFuel < target)
        {
        
            while (i < stations.size() && currFuel - stations[i][0] >= 0)
            {  //refuel at the station before it and continue
                pq.push(stations[i][1]);
                i++;
            }
             if(pq.empty())
                    return -1;
            
            int t  = pq.top();
            pq.pop();
            currFuel += t; // fuel we will have left if we topped up             
            count ++;
            
        }
       
        
        return count;
    }
};