#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
 void helper(int i, string &s, string &temp, vector<string> &ans, unordered_map<char, string> &mp){
    //base cond
    if (i >= s.size()){
        ans.push_back(temp);
        return;
    }
    
    string str = mp[s[i]];
    for (int j=0 ; j<str.size() ; j++){
        temp.push_back(str[j]);
        helper(i+1, s, temp, ans, mp);
        temp.pop_back();  //backtrack
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) return {};
    unordered_map<char, string> mp;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";
    
    vector<string> ans;
    string temp;
    helper(0, digits, temp, ans, mp);
    return ans;
    
}
};

int main ()
{
	string digits = "23";
	Solution Obj;
	vector <string> res =  Obj.letterCombinations(digits);
	for (auto elem : res)
		cout << elem << endl;
	return 0;
}
