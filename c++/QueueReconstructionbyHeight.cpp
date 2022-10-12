#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
     static bool comp(vector<int>& a, vector <int>& b) {return (a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]));};
  
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //We can sort by height first
        //Iterate through the array for the second condition and see how much i is relevant to k
        //if i > k, then shift till i ==k
        //swap operations
          
        sort(people.begin(),people.end(),comp);
        //Check each element
        vector <vector<int>> res;
        for(int i = 0;i < people.size();i++)
        {
 
                res.insert(res.begin() + people[i][1],people[i]);
        }
        
        return res;
    }
};

int main ()
{
    Solution res = Solution();
    vector <vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    for(auto a : res.reconstructQueue(people))
        for(auto b: a)
            cout << b << "\t";
    return 0;
}