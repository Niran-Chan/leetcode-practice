#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n) {
        //Recursive function
        if (n==1)
            return "1";
        //constantly determine freq of a number before change in character
        int cnt = 1;
        string res = "";
        string target = countAndSay(n-1); 
        //cout << "Iteration : " << n << "Value of target : " << target << endl;
        for(int i = 0; i < target.size();i++)
        {
            //While it is the same character, count
            if(target[i] == target[i+1])
            {
                cnt ++;
                
            }
            else 
            {   
                res += to_string(cnt) + target[i];
                cnt = 1;
            }
            
        }
        return res;
            
    
          
    };
int main ()
{
    int n = 5;
    string res = countAndSay(n);
    cout << res << endl;
    return 0;

}