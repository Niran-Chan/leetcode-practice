class Solution {
public:
    
    void dfs(int r,int c,vector<vector<int>>& mat,priority_queue<int> &pq)
    {
        if(r == mat.size()-1 || c == mat[0].size()-1 )
        {
            pq.push(mat[r][c]);
            mat[r][c] = pq.top();pq.pop();
            return;
        }
        
        pq.push(mat[r][c]);
        dfs(r+1,c+1,mat,pq);
        mat[r][c] = pq.top();
        pq.pop();
        
        return ;
        
    }
    
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        //we can dfs through each column and each row
        priority_queue<int> pq;
        for(int i =0 ; i < mat[0].size();i++) dfs(0,i,mat,pq);
        for(int i = 1; i < mat.size();i++) dfs(i,0,mat,pq);
        return mat;
        
    }
};