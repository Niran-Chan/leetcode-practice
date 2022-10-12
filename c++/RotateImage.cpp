class Solution {
public:
   
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int l =0,r = n-1,t = 0,b = n-1;
        while(t < b)
        {
            
            for(int i = 0; i < r-l;i++)
            {
                int temp =matrix[b-i][r];
                matrix[b-i][r] = matrix[t][r-i];
                matrix[t][r-i] = matrix[t+i][l];
                matrix[t+i][l] = matrix[b][l+i];
                matrix[b][l+i] = temp;
         
            }
            l++;
            r--;
            t++;
            b--;
        }
        
    }
};

