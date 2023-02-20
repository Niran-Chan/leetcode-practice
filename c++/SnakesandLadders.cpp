class Solution {
public:

    pair<int,int> getPosition (int square,int n){
        
      int r = (square-1) / n; 
        int c = (square-1) % n;
        if (r % 2)
            c = (n-1)-c;
        r = (n-1)-r;
        return {r,c};

    }
    int snakesAndLadders(vector<vector<int>>& board) {
        //BFS will let me know the fastest way without recursively going 
down a single path
        //Confusing because we read the last element as first element

        queue<int> q;
        int n = board.size();
        vector<vector<bool>>visited( n , vector<bool>(n, false)); 
        int ans =0;
        q.push(1);
        while(!q.empty() ){
            int tmpSize = q.size();
            for(int i =0; i < tmpSize;++i){
                int square = q.front();
                q.pop();
                pair <int,int> position = getPosition(square,n);
                int r = position.first,c = position.second;
                if(visited[r][c])
                    continue;
                    
                visited[r][c] = true;
        
                if(board[r][c] != -1)
                    square = board[r][c];
                
                if(square == n*n)
                    return ans;
                
                for(int x = 1; x < min(7,n*n - square + 1);++x){
                    q.push(square + x);
                }
            }
            ans++;
        }
        return -1;

    }
};
