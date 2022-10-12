class Solution {
    public String breakPalindrome(String palindrome) {
        int n = palindrome.length();
        char[] palindromeArray = palindrome.toCharArray();
        for(int i = 0; i < n / 2; i++){
            if(palindromeArray[i] != 'a'){ //'a' will be the best option
                palindromeArray[i] = 'a';
                break;
            }
            else{
                if(i + 1 == n / 2){  //If we reach the end of the string, 
all are considered 'a's. so we just replace the last char with a 'b'
				    // At this point our string only 
consists of 'a'
                    palindromeArray[n - 1] = 'b';
                }
            }
        }
        return n == 1 ? new String() : String.valueOf(palindromeArray); 
//return empty string if we encounter a length of 1
    }
}
