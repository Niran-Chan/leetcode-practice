class Solution {
public:
    static const int N = 1e5;
    int parent[N];
    long long  Size[N];
    void initialise(int n){
        for(int i=0;i<n;++i)
            {
                parent[i] = i;
                Size[i] = 1;
            }
    }
    int find(int v){
        if(parent[v] == v)
            return v;
        return parent[v] = find(parent[v]);
    }
    void Union(int a,int b){
        a = find(a);
        b = find(b);
        if(a != b){
        if(Size[b] > Size[a])
            swap(a,b); 
        parent[b] = a;
        Size[a] += Size[b];
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        //Form Union
       
        initialise(n);
        for(int i =0; i < edges.size();++i)
            Union(edges[i][0],edges[i][1]);
        long long ans = 0;
        
        unordered_map<int,int> visited;
        int visitedNodesSize = 0;
        for(int i =0;i < n;++i)
            {
                int head = find(i);
                if(!visited[head])
                    {
                        visited[head]++;
                        ans += Size[head] * (n-Size[head]-visitedNodesSize);
                        visitedNodesSize += Size[head];
                    }
            }
        return ans;
    }
};
