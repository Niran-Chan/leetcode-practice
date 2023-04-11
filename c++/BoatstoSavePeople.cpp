class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       /*
       To minimise number of boats, we need to maximise the weight of people in boat
       We can sort the people vector first, and then use two pointers
       */ 
       sort(people.begin(),people.end());
       int l =0,n = people.size(), r= n-1,ans = 0;
       while(l <= r){
           if(people[l] + people[r] <=limit){
               l++;r--;
           }
            else if (people[r] <= limit)
                r--;
            else
                return -1;
           ans++;
       }
       return ans;
    }
};
