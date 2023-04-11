class Solution {
public:

    int maxDistance(vector<vector<int>>& grid) {
        //find the 0 that is the largest distance 

        int n = grid.size();
        queue<pair<int,int>> q;
        int ans = 0;
        vector<vector<int>> visited(n,vector(n,0)); 
        //Populate cells from land cells first, and max number of 
iterations is the distance
        for(int i =0;i < n;++i)
            for(int j =0; j < n;++j)
                if(grid[i][j] == 1)
                    q.push({i,j}); //We push every land cell into a queue 
first
        int j =0; //keeping track of number of iterations
        if(q.empty()) //no land at all
            return -1;
        while(!q.empty()){
            int m = q.size();
            for(int i =0; i < m;++i){
                auto currPair = q.front();
                q.pop();
                if(visited[currPair.first][currPair.second]) //if cell has 
alr been visited, then ignore
                    continue;
                visited[currPair.first][currPair.second]=1;
                //We check if this is a water cell or a land cell
                if(grid[currPair.first][currPair.second] == 0)
                    ans = j;
                //check the neighbours of the cell
                //if equal to one, we stop right there
                if(currPair.first < n -1)
                    q.push({currPair.first + 1,currPair.second});
                if(currPair.first > 0)
                    q.push({currPair.first - 1,currPair.second});

                if(currPair.second < n -1)
                        q.push({currPair.first,currPair.second + 1});
                if(currPair.second > 0)
                    q.push({currPair.first,currPair.second - 1});
            }
            ++j;
            
        }

        return ans == 0 ? -1 : ans;
    }
};
