class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        unordered_map<char,int> vowels;
        vector<char> arr = {'a','e','i','o','u','A','E','I','O','U'};
        for(int i =0; i < arr.size();++i ){
            vowels[arr[i]]++;
        }
        int count = 0;
        for(int i =0 ; i <n;++i ){
            if(vowels[s[i]])
            {
                if(i > ((n/2) - 1))
                    count--;
                else
                    count++;
            }
        }
        return !count;
    }
};
