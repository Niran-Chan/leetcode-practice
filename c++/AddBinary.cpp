#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) 
{
    string result = "";
    int apos = a.size() - 1;
    int bpos = b.size() - 1;
    int adigit, bdigit, carry = 0;
    
    while (apos >= 0 || bpos >= 0 || carry == 1)
    {
        adigit = bdigit = 0;
        
        if (apos >= 0) adigit = (a[apos--] == '1');
        if (bpos >= 0) bdigit = (b[bpos--] == '1');
        // Another way: the digit is 1 if adigit + bdigit + carry == 1 or == 3, but I noticed that
        // XOR is more concise:
        //If carry == true, then wtv result of a digit and b digit,
        result.push_back(static_cast<char>(adigit ^ bdigit ^ carry + '0')); 
        carry = adigit + bdigit + carry >= 2;
    }
    reverse(result.begin(),result.end());
    
    return result;
};

int main()
{
string a = "11";
string b = "1";
string res = addBinary(a,b);
cout << res << endl;
return 0;

}