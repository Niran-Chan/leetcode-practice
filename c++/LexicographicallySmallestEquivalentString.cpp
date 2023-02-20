class Solution {
public:

    static const int N=200;
 
    char parent[N];

    void initialise(){
        string alphabets = "abcdefghijklmnopqrstuvwxyz";
        for(auto a : alphabets){ 
            parent[a]=a;

        }
    }
    
    char find(char a){
        if(a==parent[a]) //Recursively search for parent
            return a;
        return parent[a]=find(parent[a]);
    }

    void Union(char a, char b)
    {
        a= find(a);
        b=find(b);
        if(a!=b)
            {
            if(a > b)
                swap(a, b);
            parent[b]=a; //Attach the smaller sub tree to the larger
           
            }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        //UFDS problem
        initialise();

        for(int i =0; i < s1.size();++i){
            Union(s1[i],s2[i]);
        }
        string ans = "";
        for(int i =0; i < baseStr.size();++i){
            ans += find(baseStr[i]);
        }
        return ans;
    }
};