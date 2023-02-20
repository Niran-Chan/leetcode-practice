class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        //Straight line formula is y = mx + c
        int ans =0;
        if(points.size() <=2)
            return points.size();
        for(int i =0 ; i < points.size();++i){
            unordered_map<double,int> mp;
            for(int j= i+1; j < points.size();++j){
                //Calculate m and c values
                double x1=points[i][0],x2=points[j][0],y1 = points[i][1],y2=points[j][1];
                double m =0,c = 0;
                if(x2-x1 != 0)
                {
                    m = (y2-y1)/(x2-x1);
                }
                else{
                    m = 100000;//infinity
                }
                mp[m]++;
                
                ans = max(ans,int(mp[m]));
            }
        }
        return ans+1;
    }
};
