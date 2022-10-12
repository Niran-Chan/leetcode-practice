#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s,string t) {
        string longerString,shorterString;
        if(s.size() >= t.size()){
        	longerString = s;
        	shorterString = t;
        }
        else {
        	longerString = t;
        	shorterString = s;

        }
        
        unordered_map <char,int> map;
        int counter = longerString.size();
        //populate hashmap
        for(int i=0;i < longerString.size();i++)map[longerString[i]]++;
        for(int i =0;i<longerString.size();i++){
            if(map[shorterString[i]] > 0){
            	map[shorterString[i]]--;
            	counter --;
            }


        }
        if(counter == 0) return true;
        return false;
    }
};
int main()
{
	Solution result;
	string s= "anagram",t ="nagaam";
	bool output = result.isAnagram(s,t);
	cout << output;

	return 0;

}