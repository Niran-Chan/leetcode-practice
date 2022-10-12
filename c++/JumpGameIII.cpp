#include <bits/stdc++.h>
using namespace std;

//My solution
//Recursive function with a visited array to ensure that if visited, then return false
//DFS
/*
bool recurSoln(vector<int>&arr, int i)
{
    if (i >= arr.size() || i < 0 || arr[0] < 0 )
        return false;
    else 
    {
        arr[i] = -i;
        return ( !arr[i] || recurSoln(arr,i + arr[i])|| recurSoln(arr,i-arr[i]) );
    }
};
bool canReach(vector<int>& arr, int start) {
        bool res = recurSoln(arr,start);
        return res;
    };
    
*/

//BFS
//Check every possible path first

bool canReach(vector <int> & arr ,int start)
{
    stack <int> stk;
    stk.push(start);   
    //Push every possible path into a stack, check and repeat for every new layer of the tree
    while(!stk.empty())
    {
        int a = stk.top();
        stk.pop();

       if (arr[a] == 0)
            return true;

        if(a < 0 || a >= arr.size())
            return false;

        if (arr[a]<0) continue;
        if(arr[a] + a >= 0)
            stk.push(arr[a] + a);
        if(arr[a] - a  < arr.size())
            stk.push(arr[a] - a);
        arr[a] = -arr[a];

    }
    return false;


}

int main ()
{
vector <int> arr = {4,2,3,0,3,1,2};
int start = 5;
bool res = canReach(arr,start);
cout << res << endl;

}