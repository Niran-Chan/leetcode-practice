class Solution {
public:
    
    
    int helper (int n) 
    {
        int res=0;
        int idx=0;
         while(n)
        {
             int remainder = n % 10;
            res += pow(2,remainder); //This way, we are not nglecting the zeroes to 
add up 
            
            n /=10; 
        };
        return res;
    }
    
    bool reorderedPowerOf2(int n) {
        int a = helper(n);
        for(int i = 0; i < 30;i++)
             if (helper(1 << i) == a) return true;//powers of two
         //then numbers MUST BE THE SAME if not they just mathematically be equal to 
each other
        return false;
    }
};
