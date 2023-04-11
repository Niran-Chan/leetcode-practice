#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:


    int minDistance(vector<int> &dist, vector<bool>& visited)
{
    // Initialize min value
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < dist.size(); v++)
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    
    return min_index;
}

    void dijkstra(int n,int src,int k,vector<vector<int>> &adj,vector<int> dist,vector<bool> visited){

        dist[src]=0;
        while(k > 0){
          
            // Pick the minimum distance vertex from the set of
            // vertices not yet processed. u is always equal to
            // src in the first iteration.
            int u = minDistance(dist, visited); 
            // Mark the picked vertex as processed
            visited[u] = true;
            for (int v = 0; v < adj[u].size(); v++)
                {
            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!visited[v] && adj[u][v] && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
            }
            k--;
        }

    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<bool> visited(n,false);
        vector<int> dist(n,INT_MAX);
        vector<vector<int>> adj(n,vector<int>(n));
        for(auto a : flights){
            adj[a[0]][a[1]] = a[2]; //Edge list
        }

        dijkstra(n,src,k,adj,dist,visited);
        //Print out dist vector
        for(auto &a : dist )
            cout << a << "," << endl;
        return dist[dst];
    }   
};

int main (){

    Solution* soln = new Solution();
    int n,src,dst,k;
    vector<vector<int>> flights {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    n=4,src=0,dst=3,k=1;
    int ans = soln -> findCheapestPrice(n,flights,src,dst,k);
    cout << ans << endl;
    return 0;
}