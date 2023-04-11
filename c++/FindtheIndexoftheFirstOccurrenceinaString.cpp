class Solution {
public:
    int strStr(string haystack, string needle) {
        //We iterate through string to find first occurrence of first letter, and then compare substring.if fails, we continue searching
        if(needle.size() > haystack.size())
            return -1;
        for(int i =0;i < haystack.size() - needle.size() + 1;++i){
            if(haystack.substr(i, needle.size()) == needle)
                return i;
            cout << haystack.substr(i, needle.size()) << endl;
        }
        return haystack == needle ? 0 : -1 ;
    }
};
