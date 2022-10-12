//Concept on bit shifting
#include <iostream>
#include <climits>


int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = (dividend ^ divisor) >> 31;
        while (dvd >= dvs) {
            long temp = dvs, m = 1;
            //Bit shifting divisor and making sure <= dividend 
            while (temp << 1 <= dvd) {
                temp <<= 1;
                //Quotient also increases
                m <<= 1;
            }
            //Making sure that there is absolutely no remainder that can still divide by divisor
            dvd -= temp;
            //Final quotient value
            ans += m;
        }
        return sign?-ans:ans;
    };

int main ()
{

	return divide(100,3);
}