class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        //generate a list of the morse code version of each word
        //use hashtable to store each morse code and if its not present in the table, we can 
inc counter

        vector<string> trfTable = 
{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
      
        unordered_set <string> mp;
        for(int i = 0;i < words.size();i++)
        {
            string trfWord = "";
            for(int j =0;j < words[i].size();j++){
                 trfWord += trfTable[words[i][j] - 'a'];  
            }
            mp.insert(trfWord);
        }
        
        return mp.size();
    }
};
