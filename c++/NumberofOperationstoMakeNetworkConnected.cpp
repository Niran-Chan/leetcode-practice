class Solution {
public:
    static const int N=1e5;
    int parent[N];
    int Size[N];
    int spareCables  =0;

void initialise (int n)
{
     for(int i=0; i<n ;i++){ 
        parent[i]=i;
        Size[i]=1;
     }
}

int find(int v)
{
    if(v==parent[v]) //Recursively search for parent
        return v;
return parent[v]=find(parent[v]);

}

void Union(int a, int b)
{
    a=find(a);
    b=find(b);
    if(a== b)
        spareCables++;
    if(a!=b) 
        {
        if(Size[a]>Size[b])
            swap(a, b);
        parent[b]=a; //Attach the smaller sub tree to the larger
        Size[a]+=Size[b]; //add up the sizes to form the larger tree
        }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        //UFDS
        //If both the parents of both subtrees match, then they are already connected
        //If not, then join subtrees
        initialise(n);

        for(int i =0; i < connections.size();++i)
        {
            Union(connections[i][0],connections[i][1]);
        }
        //Now we need to find the number of disconnected trees and return value
        int ans =0 ;
        for(int i =0; i < n-1;++i){
            if(find(i) != find(i+1))
                {
                    if(spareCables == 0)
                        return -1;
                    Union(i,i+1);
                    ans++;
                    spareCables--;
                    }
        }
        //if(Size[0] != n)
          //  return -1;
        return ans;
    }
};
