class Solution {
public:
    int addDigits(int num) {
        //Keep splitting the number
        while(num >= 10){
            int tmp =0 ;
            while(num){
                int remainder = num % 10;
                num = (int)((num - remainder)/10);
                tmp += remainder;
            }
            num = tmp;
        }

        return num;
    }
};
