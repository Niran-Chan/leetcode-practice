class Solution {
public:
    static const int N=301;

    int parent[N];
    int Size[N];

    void initialise(int n){
        for(int i =0; i < n;++i){
            parent[i]=i;
            Size[i] = 1;
        }
    }

    char find(int a){
        if(a==parent[a]) //Recursively search for parent
            return a;
        return parent[a]=find(parent[a]);
    }
    bool Union(int a, int b)
    {
        a=find(a);
        b=find(b);
        if(a!=b) //not the same parent
            {
            if(Size[a] > Size[b])
                swap(a, b);
            parent[b]=a; //Attach the smaller sub tree to the larger
            Size[a]++;
            return true;
            }
        return false;

    }
   bool sameGroup(int a, int b, vector<string>& strs) {
    int n = strs[a].size(), diff = 0;
    for (int i = 0; i < n; i++) {
        if (strs[a][i] != strs[b][i]) {
            diff++;
            if (diff > 2) {
                return false;
            }
        }
    }
    return true;
}

    int numSimilarGroups(vector<string>& strs) {
        //UFDS problem
        //We use string index in strs to indicate which string
        initialise(strs.size());
        //Conditions is that one character swap should make both strings the same
        //basically find the two characters that are in a different position
        int ans = strs.size();
        for(int i =0;i < strs.size()-1;++i)
            {
                for(int j = i + 1;j < strs.size();++j){
                  // cout << strs[i] << "\t" << strs[j] << "\t" <<sameGroup(i,j,strs) << endl;
                    if(sameGroup(i,j,strs)){
                        if(Union(i,j))
                            ans--;
                    }
                }
            }
        
        return ans;
        }
};
