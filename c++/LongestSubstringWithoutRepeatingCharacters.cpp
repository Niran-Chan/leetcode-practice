class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int l =0,r = 0;
        int gmax = 0;
        while(r < s.size())
        {
            if(freq[s[r]]!=0)
            {while(l<=r && freq[s[r]] !=0)
                {freq[s[l]]--;l++;}
            }
            else{
                freq[s[r]]++;
                r++;
            }
            gmax = max(gmax,r-l);
           // cout << "Position of l:" << s[l] << "\t Position of r:" << s[r] << "\tMax:" << gmax <<endl;
            
        }
        return gmax;
    }
};