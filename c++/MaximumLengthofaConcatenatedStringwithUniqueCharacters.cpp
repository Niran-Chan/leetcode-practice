class Solution {
public:
   int maxLength(vector<string>& A) {
        vector<bitset<26>> dp = {bitset<26>()}; //character set for each 
word
        int res = 0;
        for (auto& s : A) {
            bitset<26> a;
            for (char c : s)
                a.set(c - 'a'); //setting the bit at the position true
            int n = a.count();
            if (n < s.size()) continue; //if there is one duplicate then 
continue

            for (int i = dp.size() - 1; i >= 0; --i) { //iterate backwards 
as bitset stores them in the opposite way
                bitset c = dp[i]; 
                if ((c & a).any()) continue; //Bitwise and to see if there 
are any duplicates. .any method finds for any value of bit that is set as 
1
                dp.push_back(c | a); //bitwise or to add both the bitset 
values tgt
                res = max(res, (int)c.count() + n); //c.count() to find 
number of bits set to true, which is the total number of unique characters
            }
        }
        return res;
    }
};
