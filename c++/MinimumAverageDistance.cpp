class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
       //prefix sum question
       //Keep seperate array where for each position we first have a total 
sum TO that index
       vector<long long > prefix; 
       int n = nums.size();
       long long  prev = 0;
       
       for(int i =0; i < n;++i){
            prev = prev + (long long )nums[i];
           prefix.push_back(prev);
       } 
       long long total = LLONG_MAX;
       long long tmp = 0;
       int idx = n-1;
        for(int i = 0; i < n;++i){
            if(i !=n-1)
                tmp = abs(prefix[i]/(long long )(i + 1) - 
((prefix[n-1]-prefix[i]))/(long long )(n - i -1)) ;
            else
                tmp = abs(prefix[n-1]/n);
            //cout << "tmp value : " << tmp << endl;
            if(tmp < total){
                total = tmp;
                idx = i;
                 // cout << "tmp : " << tmp << "\ttotal: " << total << 
"\tidx : " << idx << endl;
            }
        }

        return idx;
    }
};
