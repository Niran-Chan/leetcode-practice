#include <bits/stdc++.h>
using namespace std;

    vector<int> getRow(int rowIndex) {
   int row = rowIndex + 1;
        
        vector<int> pascal(row, 1);
        for (int col = 1; col < rowIndex; col++) {
            pascal[col] = ((long long)(row - col) * pascal[col - 1]) / col; 
			
        }
        
        return pascal;
    };

int main ()
{
int rowIndex = 5;
vector <int> res = getRow(5);
for(auto x: res)
	cout << x << endl;

return 0;
}
