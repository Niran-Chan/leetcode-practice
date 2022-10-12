// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
   
    
   int binarySearch(long long int l, long long int r)
    {
        if(l >= r)
            return l;
        long long int m = (l+r)/2;
        if(isBadVersion(m)) //if it is bad, we continue on the left
            return binarySearch(l,m);
        else if (isBadVersion(m) == false)
            return binarySearch(m+1,r);
        return m;
  
    }
    
    
    int firstBadVersion(int n) {
           return binarySearch(0,n);
    }
};
