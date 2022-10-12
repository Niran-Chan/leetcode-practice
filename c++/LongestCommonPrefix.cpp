#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
 string longestCommonPrefix(vector<string>& strs) {
     //Maximum can only be as long as the smallest word
    //Sort out words first, select first one and loop through
        string res = "";
        cout << strs[0]<< endl;
        bool condition = true;
        for(int a =0;a < strs[0].size();a++)
        {
            for(int b= 0;b < strs.size();b++ )
            {
                if(strs[0][a] != strs[b][a])
                {condition = false;
                break;
                }
            }
            if(!condition)
                break;
            res += strs[0][a];
            
        }
        return res;
    };
//Faster method
*/
  string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int len = 0;
        auto const& first = strs.front(); //taking the first string as the reference
        for (auto const c : first){
            for (int i = 1; i < strs.size(); ++i){
                auto const& s = strs[i];
                if (s.size() == len || s[len] != c) {
                    return first.substr(0, len);
                }
            }
            ++len;
        }
        return first.substr(0, len);
    }

int main ()
{
	vector <string> s = {"flower","flow","flight"};
	string result = longestCommonPrefix(s);
	cout << result << endl;

	return 0;
}