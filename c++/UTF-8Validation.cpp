class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        int count = 0;
      for(int i = 0; i < n; i++)
      {
          int val = data[i];
          if(!count) //We have not started the utf sequence
          {
              if((val >> 5 )== 0b110)
                    count = 1;
              else if ((val >> 4) == 0b1110)
                    count = 2;
              else if((val >> 3) == 0b11110)
                    count = 3;
              
              else if((val >> 7) ) //first bit cannot be 1
                  return false;
              
          }
          else
          {
              if((val >> 6) != 0b10) //first 2 bits not continuationthen 
return false
                  return false;
                count --;
              
          }
          
      }  
        return (count==0);
    }
};
