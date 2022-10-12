//GREAT REPRESENTATION OF USING UNORDERED_MAPS FOR HASHMAP 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;


class Solution {
public:

  
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        /* 
        //Hahmap solution
        unordered_map <int,int> map;
        int size = nums1.size()> nums2.size() ? nums1.size() : nums2.size();
        vector<int>result;
        result.reserve(size);
        for(int i=0;i<nums1.size();i++)
        {   //Populating hashmap
            // incrementing the value associated to key to the frequency of the numbers in num1
            map[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++ )
        {  
            if(map[nums2[i]]>0)
                result.push_back(nums2[i]);
                //value at key is now decremented by 1 so as to keep track of frequency of numbers in num2
                map[nums2[i]]--;
        }
        return result;
    }
    */


        //Sorting approach
        int size = nums1.size() <  nums2.size() ? nums1.size() : nums2.size();
        vector <int> result;
        result.reserve(size);
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        bool swapped = false;

        for(int x =0;x < nums1.size();x++ )
            {
                
                swapped = false;
                for(int y = x+1;y < nums2.size();y++)
                {
                    
                    if(nums1[x] == nums2[y] && find(result.begin(),result.end(),nums1[x]) == result.end())
                        {

                            result.push_back(nums1[x]);
                            
                            swapped = true;
                        }
                }
                //if(!swapped)
                  //  break;
            }
        return result;
};



};


int main (){
    
    Solution result;
    vector <int> nums1 = {1,2,2,1},nums2 = {2,2};
    vector <int> output  = result.intersect(nums1,nums2);
    cout << "[";
    for(int i =0;i < output.size();i++){
        cout << output[i] << ',';

    }
    cout << "]";
}