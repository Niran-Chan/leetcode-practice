#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int solve (vector <int> &nums){
		int shortest = 0;
        int left = 0, right = nums.size() - 1;
        while (left < nums.size() - 1 && nums[left] <= nums[left + 1]) { left++; }
        while (right > 0 && nums[right] >= nums[right - 1]) { right--; };
        
        cout << "Left most index : " << left << "\tRight Most Index : " << right << endl;
        if (right > left) {
            int vmin = INT_MAX, vmax = INT_MIN;
            for (int i = left; i <= right; ++i) {
                if (nums[i] > vmax) {
                    vmax = nums[i];
                }
                if (nums[i] < vmin) {
                    vmin = nums[i];
                }
            }
             cout << "vmin : " << vmin << "\tvmax : " << vmax << endl;
            while (left >= 0 && nums[left] > vmin) { left--; };
            while (right < nums.size() && nums[right] < vmax) { right++; };
             cout << "Left most index : " << left << "\tRight Most Index : " << right << endl;
            shortest = right - left - 1;
        }
        
        return shortest;
    };

int main ()
{
	vector <int> nums = {2,6,4,8,10,9,15};
	int output = solve(nums);
	cout << output << endl;
	return 0;
}