class Solution {
public:
    string reverseVowels(string s) {
        
        int l =0, r=s.size();
        unordered_map <char,int> mp;
        string vowels = "aeiouAEIOU";
        for(auto &a : vowels)
            mp[a]++;
        
        while(l < r){

            while(l < r && mp[s[l]] == 0)
                l++;
            while(l<r && mp[s[r]] == 0)
                r--;
            swap(s[l],s[r]);
            l++;r--;

        }
        return s;
    }
};
