class Solution {
public:
    int startingpix;
    void dfs(vector<vector<int>> &image,int i,int j,int color)
    {
        if(i < 0|| i > image.size()-1|| j < 0 ||j > image[0].size()-1) return;
        if(image[i][j] != startingpix|| image[i][j] == color) return;
       
        image[i][j] = color;

        dfs(image,i,j+1,color);
        dfs(image,i,j-1,color);
        dfs(image,i+1,j,color);
        dfs(image,i-1,j,color);

        return;
         
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        startingpix = image[sr][sc];
        dfs(image,sr,sc,color);
        return image;
    }
};