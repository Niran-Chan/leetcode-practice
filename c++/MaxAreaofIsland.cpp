#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int helper(vector<vector<int>> &grid,int row,int col)
    {
        if(row == grid.size() || row < 0 ||  col == grid[0].size() || col < 0 ||   grid[row][col] == 0) //row & column SHOULD NOT be out of range
            return 0;
        grid[row][col] = 0;
        return  helper(grid,row+1,col)+1+helper(grid,row,col+1) + helper(grid,row-1,col) + helper(grid,row,col-1); //1 is the current value of the node, which by all means mean that we can reuse this solution for other problems as well if we replace it with a variable
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
  
        int maxArea = 0;
        for(int i =0; i < grid.size();i++)
        {
            for(int j =0;j < grid[0].size();j++ )
            {maxArea = max(helper(grid,i,j),maxArea);}
        }
        return maxArea;
    }
};

int main ()
{
Solution obj;
vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
cout << obj.maxAreaOfIsland(grid);

return 0;}
