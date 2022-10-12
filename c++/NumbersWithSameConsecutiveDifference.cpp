class Solution {
public:
    
    void backtrack(int digit,int cnt,int n, int k, vector<int> &v)
    {
        if( cnt == n)
        {v.push_back(digit);return;};
        
        int lastDigit = digit % 10;
        if((lastDigit + k) > 9 && (lastDigit - k) <0)
            return;

        digit *= 10;
        //iterate forwards
        if(lastDigit + k < 10)
        {
            int x = lastDigit + k;
            digit += x ;
            backtrack(digit,cnt+1,n,k,v);
            digit -= x; 
        }
        if(lastDigit - k >= 0 && k !=0)
        {
             int x = lastDigit - k;
           digit += x ;
            backtrack(digit,cnt+1,n,k,v);
            digit -=x; 
            
        }
        return;
        
    }
    
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
 
        vector<int> v;
        int cnt =0;
        for(int i = 1; i < 10;i++) //numbers to
        {
            backtrack(i,cnt+1,n,k,v);
            
        }
        
        return v;
        
    }
};