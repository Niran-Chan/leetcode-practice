#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	bool binarySearch(vector<int> arr,int left,int right,int target)
	{	//If right subarray still exists
		if(right >= left)
		{	
			//calculate the mid point for recursive later on
			int mid = (right+left)/2 ;
			cout << mid << endl;

			//mid point is the target
			if (arr[mid] == target) return true;

			//target is on the left side
			else if(arr[mid] > target) return binarySearch(arr,left,mid-1,target);

			//target on right side
			else if (arr[mid] < target) return binarySearch(arr,mid+1,right,target);

		}
		return false;

	}


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int rows = matrix.size(),cols=matrix[0].size();

       vector <int> matrixFlattened (rows*cols);
       for(int row =0;row < rows;row++){for(int col = 0;col < cols;col++)matrixFlattened[row*cols+col] = matrix[row][col];}
/*
        int* ptr = &matrix[0][0];
        
       	//Shifting with pointers
	    
	    //****************
	    for ( const auto &row : matrix )
			{
    			for ( int x : row ) {*ptr++ = x;matrixFlattened.push_back(x);}
			
			}	


        for(auto x:matrixFlattened){

        	cout << x << endl;
        }

    for(auto x:matrixFlattened){

        	cout << x << endl;
        }
*/


    

    	bool isValid = binarySearch(matrixFlattened,0,matrixFlattened.size()-1,target);

        return isValid;
    }
};





int main(){


//vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}}; 
int target = 13;

Solution result;

bool output = result.searchMatrix(matrix,target);

cout << output;


return 0;	
}