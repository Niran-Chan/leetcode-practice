class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0 ) return false;
        int x = log10(n)/log10(2);
        return(pow(2,floor(x)) == n);
    }
};