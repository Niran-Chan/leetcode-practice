//IMPORTANT EXAMPLES ON 2D TO 2D MATRIX REARRANGEMENT

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

vector <vector <int>> result (r, vector<int>(c)) ;        
int m = mat.size(),n = mat[0].size();

//Check if reshaping possible
if (r*c != n*m) return mat;

for (int i=0;i <r*c;i++)
        {
            result[i/c][i%c] = mat[i/n][i%n];
        }


return result;
}
};



int main ()
{
Solution result;
vector <vector <int>> mat = {{1,2},{3,4}};int r = 4,c = 1;vector<vector<int>> output = result.matrixReshape(mat,r,c);
cout << "OUTPUT:\n";
for(auto x: output){ for(auto y:x){cout << y  << " ";} cout << endl;}

}