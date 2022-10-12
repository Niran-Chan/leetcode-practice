#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        
        int max_digit = 0;
        //For each character, we need to find out if 
        for (char digit: n) {
            max_digit = max(max_digit, digit - '0');
        }
        return max_digit;
    }
    
};

int main ()
{
Solution Obj;
string n = "82534";
cout << Obj.minPartitions(n) << endl;;

return 0;
}
