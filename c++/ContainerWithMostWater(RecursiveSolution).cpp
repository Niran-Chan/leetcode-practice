#include <iostream>
#include <vector>

using namespace std;
 int maxArea(vector<int>& height) {
        //2 pointer Approach
        int i=0,j = height.size() -1;
        int maxH = 0;
        while(i < j){
            //Identify the maximum height
            int currH = min(height[j],height[i]);
            maxH = max(maxH,(j-i) * currH);
            //Time to find any higher elements
            while(i<j && height[i] <= currH )i++;
            while(i<j && height[j] <= currH)j--;
            
        }
        return maxH;
        
};

int main ()
{
vector <int> height = {1,5,4,3,2,4};
int res = maxArea (height);
cout << res << endl;
return 0 ;
}