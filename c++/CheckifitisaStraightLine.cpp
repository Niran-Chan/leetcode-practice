class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& a) {
        //check if y = mx
        for(int i =2; i < a.size();++i)
        {
            int y3 = a[i][1],y2 = a[i-1][1],y1 = a[i-2][1],x3 = a[i][0],x2 
= a[i-1][0],x1 = a[i-2][0];
            if((y3-y2)*(x2-x1) != (y2-y1)*(x3-x2))
                return false;
        }
        return true;
    }
};
