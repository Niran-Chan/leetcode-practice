class Solution {
public:

    int solve(vector<int> root,int& path,vector<vector<int>>&grid,int& n, int& k){
        int rows = grid.size();
        int cols = grid[0].size();
        if(root[0]== rows || root[0] < 0 || root[1] == cols || root[1] < 0)
            return 0;
        if(grid[root[0]][root[1]] == -1 )
            return 0;
        if(grid[root[0]][root[1]] == 2)
            {
                if(path == n - k)
                {
                    return 1;
                }
                else
                    return 0;

            }
        grid[root[0]][root[1]] = -1; 
        path += 1;
        int left = solve({root[0],root[1] - 1},path,grid,n,k);
        int right =solve({root[0],root[1] + 1},path,grid,n,k);
        int bottom = solve({root[0] - 1,root[1]},path,grid,n,k);
        int top = solve({root[0] + 1,root[1]},path,grid,n,k);
        path -= 1;
        grid[root[0]][root[1]] = 0;
        return left + right + top + bottom;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        //From the starting path, we walk over each and every possible path, append it to the final path if our visited path size is the n-1-k, where k is the number of blocked paths
        int n = grid.size();
        int m = grid[0].size();
        //We traverse the grid once to find out the number of blocked paths
        int k =0;
        vector<int> startingPoint = {0,0};
        int allElements = 0;
        for (int i =0; i < n;++i){
            for (int j =0 ; j < m;++j){
                allElements++;
                if(grid[i][j] == -1)
                    ++k;
                else if (grid[i][j] == 1)
                    {
                        startingPoint[0] = i;
                        startingPoint[1] = j;
                    }
                    
            }
        }
        allElements -= 1;
        int path =0 ;
        path = solve(startingPoint,path,grid,allElements,k);
        return path;
    }
};