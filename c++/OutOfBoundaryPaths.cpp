#include <bits/stdc++.h>

using namespace std;
class Solution {
private : 
    int M,N;
    int dfs [51][51][51];
    long long int MOD = pow(10,9)+7;
    public:
    
    int helper(int i,int row,int col)
    {
        
        
        if(row < 0 || row == M || col < 0 || col == N )
            return 1;
     //We reach end
           if(i <=0)
            return 0;
        
        if(dfs[i][row][col] != -1)
            return dfs[i][row][col];
        //Traverse ALL 4 paths recursively
        int up =0,down=0,left=0,right=0;
        down = helper(i-1,row + 1,col);
        up = helper(i-1,row-1,col);
        right = helper(i-1,row,col+1);
        left = helper(i-1,row,col-1);
        
        return dfs[i][row][col] = (up % MOD + down % MOD + left % MOD + right % MOD ) % MOD ;
        
            
        
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        //Recursively see if we reach a corner / side cell
        //we have a cache to store any existing paths that we already prepare to undertake (*OPTIMISATION*) dfs[maxMove][row][col]
        M = m,N=n;
        memset(dfs,-1,sizeof(dfs));
        return helper(maxMove,startRow,startColumn);
    }
};

int main ()
{

Solution obj;
cout << obj.findPaths(2,2,2,0,0);

return 0;
}
