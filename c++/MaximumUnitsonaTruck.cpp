#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    
    static bool comp(vector <int> &a,vector <int> &b)
    { 
        return a[1] > b[1];
        }
    
    int maximumUnits(vector<vector<int>>& A, int truckSize) {
      //Sort by second element (maximum number of units with minimal number of boxes)
     sort(A.begin(),A.end(),comp);
        
        int res = 0;
        int trucks = 0;
        for(int i =0; i < A.size();i++)
        {
            if(trucks + A[i][0] > truckSize)
                return res += A[i][1] * (truckSize-trucks);
                
            else
            {
                trucks += A[i][0];
                res += A[i][0] * A[i][1];
            }
            
        }
        return res;
    
    }
};
int main ()
{

Solution Obj;
vector <vector <int>> A = {{1,3},{2,2},{3,1}};
int truckSize = 4;
cout << Obj.maximumUnits(A,truckSize) << endl;
return 0;

}
