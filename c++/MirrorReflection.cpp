class Solution {
public:
    int mirrorReflection(int p, int q) {
        
        int g= __gcd(p,q);
        p /=  g;
        q /= g;
        
        //both p qnd q can't be even
        if((p%2)==0 && (q%2)!=0){
            return 2;//when p is even and q is odd
        } 
        if((p%2)!=0 && (q%2)!=0){
            return 1;// when p is odd and q is odd
        } 
        return 0;// when p is odd and q is even
    }
};
