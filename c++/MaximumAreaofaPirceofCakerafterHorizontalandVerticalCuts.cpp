#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	Solution (){};

    int maxDiff(vector<int>& v,int a)
    {
        int m = v[0];
        for(int i =1; i < v.size();i++) 
            m =  max(m,v[i]-v[i-1]);
        m = max(a-v[v.size()-1],m);    

        return  m;
    }
    
    
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
    sort(hCuts.begin(),hCuts.end());
    sort(vCuts.begin(),vCuts.end());
    

        //Now we iterate thru and find max difference in both horizontal and vertical
        long long int hm,vm;
        hm = maxDiff(hCuts,h);
        vm = maxDiff(vCuts,w);
        return (hm * vm)%1000000007;
    }
};

int main ()
{
	Solution obj;
	int h=5,w=4;
	vector <int> hCuts = {1,2,4},vCuts ={1,3} ;
	cout << obj.maxArea(h,w,hCuts,vCuts) << endl;
	return 0;

}
