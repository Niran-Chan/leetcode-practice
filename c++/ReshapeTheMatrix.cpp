#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

vector <vector <int>> result (r+1, vector<int>(c+1)) ;        
vector <int> midResult ;
int initialColumns = mat.size(),initialRows = mat[0].size();

//Check if reshaping possible
if (r*c != initialRows*initialColumns) return mat;

//To populate result, need to convert two dimension array to one dimension
//simple solution is to for loop twice but O(N^2) time complexity

int *ptr = &mat[0][0];
for(int i = 0 ; i<r*c;i++)\
{
    //increasing memory address by i, and dereferencing the pointer
   midResult.push_back(*ptr+i);
}
int rIdx=0,cIdx=0;
for(int item : midResult)
{   
    if(cIdx >c){cIdx=0;rIdx++;}
     {

        result[rIdx][cIdx]=item;
        cIdx++;

    }

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