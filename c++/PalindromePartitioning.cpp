class Solution {
public:

vector<vector<string>> ans;
unordered_map<string,int> cache;
bool isPalindrome(string a){
    int l =0,r = a.size()-1;
    while(l<r){
        if(a[l++] != a[r--])
            return false;
    }
    return true;
}

void solve(int start,vector<string> combs,string &s){
    if(start == s.size())
    {
                ans.push_back(combs);
    }

    for(int i = start; i < s.size();++i ){
        string target = s.substr(start,i-start+1);
        
        if(!cache[target]){
            cache[target] = isPalindrome(target) + 1;
        }
        if(cache[target] == 2){
            combs.push_back(target);
            solve(i+1,combs,s);
            combs.pop_back();
        }

    }    
    }

    vector<vector<string>> partition(string s) {
        solve(0,{},s);
        return ans;
    }
};
