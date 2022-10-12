#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int index =-1;
        unordered_map <char,int> map;
        //populate hashmap
        for(int i=0;i < s.size();i++)map[s[i]]++;
        for(int i =0;i<s.size();i++)if(map[s[i]]==1){index=i;break;}

        return index;
    }
};
int main()
{
	Solution result;
	string s = "leetcode";
	int output = result.firstUniqChar(s);
	cout << output;

	return 0;

}