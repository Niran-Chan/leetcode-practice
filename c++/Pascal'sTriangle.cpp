#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
	/*
	int factorial(int x)
	{	
		if(x <= 1)return 1;
		else return factorial(x-1) * x;
		
	}
*/

    vector<vector<int>> generate(int numRows) {
	  /*
		vector<vector<int>> result ;

      
		//For each row
		for(int row = 0;row < numRows;row++)
		{
			vector <int > rowOutput = {1};
			
				//	cout << "{";
			//value at each spot
			for(int C=1;C < row + 1;C++)
			{
				//(factorial(row))/(factorial(C)*factorial(row-C))
				int total = factorial(row)/(factorial(C)*factorial(row-C));
				rowOutput.push_back(total);

				//cout << "{" << rowOutput[C] << "}" << (C == row-1)?"":",";
			}

			result.push_back(rowOutput);
			//cout << "}";
		*/

	//Instead of factorial, we can just sum up the numbers before
	vector<vector<int>> result;
		for(int i = 0; i < numRows;i++)
		{   //initiliase i+1 size vector with 1 filled
			vector <int> rowOutput(i+1,1);
			for(int j=1;j < i;j++)
			{
				rowOutput[j] = result[i-1][j] + result[i-1][j-1];
			}
            result.push_back(rowOutput);
		}


	return result;        
    }
};

int main ()
{

int numRows = 25;
Solution result;
vector<vector<int>> output = result.generate(numRows);
for(auto x: output)
{
	for(auto y: x)
	{
	cout << y << endl;
	}
}	
	


	return 0;
}


