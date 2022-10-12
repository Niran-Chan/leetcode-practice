#include <bits/stdc++.h>

using namespace std;

 int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        //We use bricks all the way
        //We use the ladder ONLY for the largest diffs
        //Lets use a priority queue to tell us how many ladders we can best use
        priority_queue <int> btol; 
        for(int i =1; i < heights.size();i++)
        {
            if(heights[i] - heights[i-1] <=0)
                continue;
            
            int d =(heights[i] -heights[i-1]);
            bricks -= d;
            btol.push(d);
            if(bricks  < 0)
            {
                bricks += btol.top() ;
                btol.pop();
                if (ladders == 0)
                    return i-1;
                ladders--;
       
            }
          
        
        }
        return heights.size()-1;
        
    };

int main ()
{
vector <int> heights = {2,7,9,12};
int bricks = 5;
int ladders = 1;
int res = furthestBuilding(heights,bricks,ladders);
cout << res << endl;
return 0;
}
