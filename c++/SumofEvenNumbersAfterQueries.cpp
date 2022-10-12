class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        //Each query in the array changes the values of the nums array
        //time complexity O(N)
        
        int n = nums.size();
        int m = queries.size();
        vector<int> arr(m);
        
        int ans =0;
        for(int i =0 ; i < n;i++)
            if(nums[i] %2 == 0)
                ans += nums[i];
        
        for(int i =0;i < m;i++)
        {
            int index = queries[i][1];
            int val = queries[i][0];
            int q = nums[index];
                 
            nums[index] = q + val ;
            
            int wasOdd = q%2;
            if((nums[index]%2) != 0) //if it was previously odd and now its even, add the new number
            {
                if(wasOdd == 0)
                    ans-= q; //remove initial value
                            //if still odd continue
            }
            else{
                if(wasOdd != 0) //if now its even and it was odd, we add the whole number
                    ans+= nums[index];
                else
                    ans+= val; //if it was not odd, we add the top up
            }
            arr[i] = ans;
        }
        
        return arr;
    
    }
};