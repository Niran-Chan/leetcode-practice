class Solution {
public:
    bool check(int &days,vector<int> &weights,int cap){ //Check if the current capacity is valid for the array
        int currWeight = 0,daysReq = 0;
        for(int weight : weights){
            if(currWeight + weight > cap)
            {
                currWeight = weight;
                daysReq++;
            }
            else
                currWeight += weight;
        } 
        return daysReq < days; //1 based indexing so not <= but <

    }
    int shipWithinDays(vector<int>& weights, int days) {
        //As days increase, We split the load into half
        //l = largest weight, r= totalSum
        int l = INT_MIN,r = 0;
        for(auto &a : weights)
            {r +=a;l = max(l,a);}
        int ans = r;
        while(l <= r) //while our max weight is smaller than the total sum
        {
            int m = (l+r)/2;

            if(check(days,weights,m))//if current capacity works, then we want to shift to the left side
            {
                ans = m;
                r = m-1;
            }
            else
                l = m+1;
        }
        return ans;
    }
};