#include <bits/stdc++.h>

using namespace std;

bool divisorGame(int n) {
        bool alice = true;
        int x = n;
        while(n)
        {
            for(int i = 1; i < n; i++)
            {
                if(n % i == 0)
                {
                    x = i;
                    break;
                }
            }
            n -= x;
            
            //If alice is true, then its her turn
            alice = !alice;
        }
        
        return alice;
    };

int main ()
{

    int n = 5;
    divisorGame(n);

    return 0;
}