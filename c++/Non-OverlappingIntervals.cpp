class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[ ]( const vector<int>& 
lhs, const vector<int>& rhs )
{
   return lhs[1] < rhs[1];
}); //When we sort, we sort by range as well
        int end = intervals[0][1];
        int ans =0 ;
      
        for(int i =1; i < intervals.size();++i)
            {
                if(intervals[i][0] < end){
                    ans++;
                }

                else{
                    end = intervals[i][1];
                }

            }
        return ans;

    }
};
