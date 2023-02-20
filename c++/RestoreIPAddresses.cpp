class Solution {
public:

    bool isValid(string &a){
        int digit = stoi(a);
        if(digit >= 0 && digit <=255)
            return true;
        return false;
    }
    vector<string> ans;
    void solve(int i,string curr, string &s){
        if(i == s.size())
        {
            curr.pop_back();
            int cnt = count(curr.begin(),curr.end(),'.');
            if(cnt == 3)
                ans.push_back(curr);
            return;
        }
        for(int x = i+1;x <= s.size();++x){
            if(x == i + 4)
                break;
            string target = s.substr(i,x-i);
            if(isValid(target))
                {
                    curr += target + ".";
                    solve(x,curr,s);
                    curr = curr.substr(0,curr.size()-x+i-1);
                    if(target == "0")
                        break;
                }
            else
                break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        //Recursively try and see if we can place in a dot or not
        //and if the conditions are not fulfilled, then we can skip this 
string
        solve(0,"",s);
        return ans;
    }
};
