#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote,string magazine) {
        
        unordered_map <char,int> map;
        //populate hashmap
        for(int i=0;i < magazine.size();i++)map[magazine[i]]++;
        for(int i =0;i<ransomNote.size();i++){
            if(map[ransomNote[i]] ==0){return false;}
            else if(map[ransomNote[i]]){map[ransomNote[i]]--;}


        }
        return true;
    }
};
int main()
{
	Solution result;
	string ransomNote= "aa",magazine ="aab";
	bool output = result.canConstruct(ransomNote,magazine);
	cout << output;

	return 0;

}