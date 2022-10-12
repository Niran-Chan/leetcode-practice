#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        //m is number of rows, n is number of cols
        int m = v.size()-1,n=v[0].size()-1 ;
        vector<vector<long int>> A (m+1, vector<long int>(n+1, 0));
        //Assuming that both paths above it and to its left will conclude

        for(int row = m;row >=0;row--)
        {
            for(int col=n;col >=0;col--)
            {
               if(row == m && col == n)
               {A[row][col] = v[row][col] == 1 ? 0 : 1;continue;}
                /*
                Case 1: If any index on the left most column, right most column, first row or the last row will lead to all indexes past that index to only contain 0 paths
                Case 2: Any index in between the grids with an obstacle are marked as 0 paths
                */
                if(A[m][n] == 0)
                    return 0;
                if(v[row][col] == 1)
                    A[row][col] = 0;
                //Case 1 : 
                //Last and first Cols
                else if(row == m)
                    A[row][col] = (v[row][col] == 1 || col < n  && A[row][col+1] == 0) ? 0 :1;
                else if(col == n )
                    A[row][col] = (v[row][col] == 1 ||row < m  && A[row+1][col] == 0 ) ? 0 : 1;
                
                //Case 2
       
                else
                    A[row][col] = A[row+1][col] + A[row][col+1]; 
                    
                
            }
            
        }
        
        
        /////////////
        //DEBUGGING//
        /////////////
       
      /*  
        for(auto row : A)
        {
             cout << "[";
            for (auto col : row)
                cout << col << ",";
            cout << "]"<<",";
         }
         
        */
        return A[0][0];
    }
};



int main ()
{
	Solution obj;

	vector <vector <int >> nums  = {{0,0,0},{0,1,0},{0,0,0}};
	cout << obj.uniquePathsWithObstacles(nums) << endl;
	return 0;

}