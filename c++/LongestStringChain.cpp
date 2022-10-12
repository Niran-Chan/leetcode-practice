#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int longestStrChain(vector<string>& words) {
        int cnt = 1;
        //Needed to add this comparative function as the sort function does not sort the string according to their length but most likely the ascii values
        sort(words.begin(),words.end(),[](const string &a,const string &b){return (a.size() < b.size());});
        unordered_map <string,int> mp;
        
        //Now we iterate through each word and each character deletion to see if we can find a corresponding word
        //MEMOIZATION
        //We are storing the chain length in each mapped string 

        for(int i = 0; i < words.size();i++)
            {
            string word = words[i];
            mp[word] = 1;
            for(int x = 0; x < word.length();x++)
            {
                string target = word.substr(0,x) + word.substr(x+1);
                //Find from hashmap
                if(mp.find(target) != mp.end())
                {
                	//For the provided test cases, we don't need max as we are 
                	//assuming that there are no more unique strings to compare
                    mp[word] = max(mp[word],mp[target] + 1);
                    cnt = max(cnt,mp[word]);
                  
                    
                }
            }
            
        }
        return cnt;
    };



int main ()
{
	vector <string> words = {"a","b","bda","bca","bdca","ba"};
	int res = longestStrChain(words);
	for(auto x : words)
		cout << x << "\t"; 
	return 1;


}