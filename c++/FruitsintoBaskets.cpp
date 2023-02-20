class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //finding max subsequences
        int start =0,ans = 1,a = fruits[0],b=-1,cnt = 1,i = 1;

        while(i < fruits.size()){

            if (b == -1 && fruits[i] != a)
                {b = fruits[i];cnt++;start = i;}

            else if(fruits[i] != a && fruits[i] != b)
                {a = fruits[start];b = -1;cnt = 1;i = start;}
            else 
                cnt++;
            ans = max(ans,cnt);
            ++i;
        }
        return ans;
    }
};
