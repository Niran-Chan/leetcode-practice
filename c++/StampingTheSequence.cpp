#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>


using namespace std;

class Solution {
public:
    
    bool canReplace(string &stamp,string &target,int pos){
        int m=stamp.size(),n=target.size();
        for(int i=0;i<m;i++){ 
            if(target[i+pos]!='?' and target[i+pos]!=stamp[i]) //Since we are backtracking, if the value is a question mark we dont want to replace it
                return false;   //Also, we can only remove it if its part of the stamp and we are checking each and every part of the stamp
        }
        return true;
    }
    
    
    int replace(string &stamp,string &target,int pos){
        int cnt=0;
        int m=stamp.size(),n=target.size();
        for(int i=0;i<m;i++){
            if(target[i+pos]!='?'){
                cnt++;
                target[i+pos]='?';
            }
        }
        return cnt;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        
        vector<int> ans;

        int m=stamp.size(),n=target.size();
        
        int count=0;
        
        vector<int> vis(n+1,0); //Visited array
        
        while(count!=n){ //While we are still smaller than target
            bool flag=false;
            for(int i=0;i<=n-m;i++){ //The whole stamp needs to fit in
                if(!vis[i] and canReplace(stamp,target,i)){ //If not visited and passes our Replace funciton
                    vis[i]=1;   //Count node as counted
                    count+=replace(stamp,target,i); //increase the count so that we can eventually reach our target
                    flag=true; 
                    ans.push_back(i); //push back i value as possible
                    if(count==n) break; //break out as we have reached the target length
                }
            }
            if(!flag) return {};
        }
        reverse(ans.begin(),ans.end()); //reverse answer as we finished backtracking
        return ans;
    }
};
int main(){
    string stamp = "abc", target = "ababc"; //Expected Answer : [0,2]
    stamp = "abca", target = "aabcaca"; //Expected Answer : [3,0,1]
    Solution* soln = new Solution();
    vector<int> ans = soln -> movesToStamp(stamp,target);
    cout << "[";
    for(auto &a : ans)
        cout <<a << ",";
    cout << "]";
    return 0;
}