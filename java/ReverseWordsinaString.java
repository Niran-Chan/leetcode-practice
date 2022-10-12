class Solution {
    public String reverseWords(String s) {
        //use stack to store then pop into new string
        Stack <Character> stk = new Stack<>();
        String ans = new String();
        
        for(int i =0; i < s.length();i++) //iterate through each word, if we see whitespace we clear stack
        {
          
            if(s.charAt(i) == ' ')
            {
                while(!stk.empty())
                    {

                        ans+= stk.peek();
                        stk.pop();

                    }
                  ans += ' ';
            }
            else
                stk.push(s.charAt(i));
        
        }
        while(!stk.empty())
                {

                    ans+= stk.peek();
                    stk.pop();

                }
    
        
        return ans;
    
    }
}