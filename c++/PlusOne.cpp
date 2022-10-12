#include <iostream>
#include <vector>


using namespace std;


 vector<int> plusOne(vector<int>& digits) {
     int size=digits.size();
         vector <int> alt (digits.size()+1,{0});
         alt[0] = 1;  
         //Iterate from the back
        for(int i=size-1; i>=0; i--)
        {
            if(digits[i]!=9)  // if last element is not 9 
            {
            digits[i]=digits[i]+1;  //simply add one in last element and return array
            return digits;
             }
            else
               digits[i]=0;  //if last element is 9 then make last element 0 
            
        }                         //if all the digits are 9 for ex:-999 loop will make it 000
        //digits.insert(digits.begin(),1); // if all digits are 9 and we got 000 in vector digits so now 
        return alt;                  //simply we need to insert 1 in begining of 000 i.e 1000
    };



int main ()
{
	vector <int> digits = {9,9,9};
	vector <int> res = plusOne(digits);
	cout << "[";
	for(auto elem : res)
		cout << elem << ",";
	cout << "]";
	return 0;
}