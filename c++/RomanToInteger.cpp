#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
        //Map each letter to each integer, and enumerate from the back
        unordered_map <char,int> table= {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int res = table[s.back()];
        for(int i = 0; i < s.size() -1 ; i++)
        {
            if(table[s[i]] < table[s[i+1]])
                res -= table[s[i]];
            else
                res += table[s[i]];
        }  
        return res;
    };

int main ()
{

	string s = "III";
	int result = romanToInt(s);
	cout << result << endl;
	return 0;
}