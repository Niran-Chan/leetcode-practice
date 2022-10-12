#include <iostream>
#include <vector>
#include <string>

using namespace std;

 string convert(string s, int numRows) {
        //Case of just one row, algorithm not necessary
       if(numRows == 1)
           return s;
        //Offset from each character
        int offset  = (numRows-1) * 2;
        string ans = "";
        //For each row
        for(int r =0;r < numRows;r++)
       {  
            for(int i = r ;i < s.size();i +=offset)
            {       
                int midOffset = i + offset - 2*r;
                ans += s[i];
                //Adding the characters in between each offset
                if(r > 0 && r < numRows - 1 && midOffset < s.size())
                    ans+=s[midOffset];
                
            }
            
       }
        return ans;
    };



int main (){

	string s = "ABCDEFGHI";
	int numRows = 4;
	string res = convert (s, numRows); 
	cout << res << endl;
	return 0;
}