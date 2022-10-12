class Solution {
public:
 static const int N=1e6;
 
int parent[N];
int Size[N];

void initialise ()
{
     for(int i=0; i<26 ;i++){ 
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
    a= find(a);
    b=find(b);
    if(a!=b)
        {
        if(Size[a]>Size[b])
            swap(a, b);
        parent[b]=a; //Attach the smaller sub tree to the larger
        Size[a]+=Size[b]; //add up the sizes to form the larger tree
        }
}
                                                       
    bool equationsPossible(vector<string>& equations) {
        
       initialise();
        //Conduct all union operations first
        for(auto e: equations){
            if(e[1]=='='){
                Union(e[0]-'a', e[3]-'a');
            }
        }
        //Conduct all disjoint operations
        
        for(auto e: equations){
            if(e[1]=='!'){
                int p1=find(e[0]-'a');
                int p2=find(e[3]-'a');
                if(p1==p2)return false;
            }
        }
    return true ;
    }
};

