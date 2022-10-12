class Solution {
public:
    
    int find_max(vector<int>& arr, int k)
    {
        int n = arr.size();
        int maxi = INT_MIN;
        int curr_sum = 0; // curr_sum will store cumulative sum
        set<int> s;// set will store the prefix sum of array 
        s.insert(0); // put 0 into set, if curr_sum == k, (curr_sum - k) will be zero 
        
        for(int i = 0; i < n; i++)
        {
            curr_sum += arr[i];      // calculate cumulative sum
            auto it = s.lower_bound(curr_sum - k); // find the prefix sum in set having sum == curr_sum - k  
            if(it != s.end())  // if prefix sum is present, update the maxi
            {
                maxi = max(maxi, curr_sum - *it);
            }
            s.insert(curr_sum);     // insert prefix sum into set
        }
        
        return maxi;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = INT_MIN;
        
        // fix the position two rows and take cumulative sum of columns between two fixed rows
        
        for(int start_row = 0; start_row < n; start_row++)
        {
            vector<int> col_array(m, 0);
            for(int end_row = start_row; end_row < n; end_row++)
            {
                for(int col = 0; col < m; col++)     // take cumulative sum of columns between two fixed rows
                {
                    col_array[col] += matrix[end_row][col];
                }
                
                // find maximum subarray having sum less than equal to k
                
                int curr_max = find_max(col_array, k);
                
                // update the maximum sum
                
                maxi = max(maxi, curr_max);
            }
        }
        
        return maxi;
    }
};