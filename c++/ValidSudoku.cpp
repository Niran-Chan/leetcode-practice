#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>

//Excellent example on how to use hashmap for a more efficient O(n^2) operation
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
    	/*
        vector<vector<int>> boardConverted (9,vector<int>(9,0)) ;

        //Convert periods to 0s and everything else to integers
        //Populated new vector with integers
        for(int row =0;row < 9;row++)
        {
        	for(int col = 0;col < 9;col++ ) {
        		boardConverted[row][col] = (board[row][col] == '.')?0:(int)(board[row][col])-48;
        		//cout << boardConverted[row][col] << " ";
        	};

        }
		*/
    	//hashtable method
    	//array of size 3 and datatype int inside map
    	unordered_map <char,int[3]>map[9];
    	//pair <int,int> pair;
    	//Populate hashtable
    	for(int row = 0;row < 9;row++)
    	{
    		for(int col = 0;col < 9;col++) {
    			char currentValue = board[row][col];
    			if( currentValue != 46){
    				//If number exists in row	 || number in column || number in 3x3 box

    				if(map[row][currentValue][0]++ > 0 || map[col][currentValue][1]++ > 0 || map[row/3*3+col/3 ][currentValue][2] ++ > 0 ) return false;
				
    			
    			
    			}
    		}
   			//cout <<"Key:" << board[i][0]<<"\n Value :"<<map[board[i][0]*1*1] << endl;
    		
    	}


        return true;
    }
};



int main()
{
	//Testcase 1: Returns true

	vector <vector <char>> board = 
{
{'5','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}
};



/*

//Testcase 2 returns false
vector <vector <char>> board = 
{
{'8','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}
};
*/


	Solution result;

	bool output =  result.isValidSudoku(board);
	cout << output;
	return output;

}