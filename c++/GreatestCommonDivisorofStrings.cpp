class Solution {
public:
    string gcd(string str1, string str2)
    {
        if (str1.length() > str2.length())
            return gcd(str2, str1); 
        else if (str1 == "")
            return str2;
    
        else if(str2.find(str1) == str2.npos)
            return "";
        
  
        else
            return gcd(str1,str2.substr(str1.length()));
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1.size() > str2.size() ) //str 1 has the smaller size
            return gcdOfStrings(str2,str1);
        
        string result = gcd(str1,str2);
        return result;  

    }
};
