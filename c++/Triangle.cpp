class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        //keep tracking the minimum that we can get and make a prefix sum
        for(int r = 1;r < triangle.size();r++)
        {
            for(int c = 0;c < triangle[r].size();c++)
                if(c == triangle[r].size()-1) triangle[r][c] = triangle[r-1][c-1] + triangle[r][c];
                else if (c == 0) triangle[r][c] = triangle[r-1][c] + triangle[r][c];
                else triangle[r][c] = min(triangle[r-1][c-1],triangle[r-1][c]) + triangle[r][c];
        }
        sort(triangle[triangle.size()-1].begin(),triangle[triangle.size()-1].end());
        return triangle[triangle.size()-1][0];
    }
};