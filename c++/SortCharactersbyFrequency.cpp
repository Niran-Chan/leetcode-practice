class Solution {
public:
    string frequencySort(string s) {
        //easy way is to generate hashmap, iterate through keys
        //key and value pair into priority_queue for sort, pop and return 
final string
        unordered_map <char,int> mp;
        priority_queue<pair<int,char>> pq;
        for(auto& a : s){
            mp[a]++;
        }
        string ans = "";
        for(auto a : mp){
            pq.push(make_pair(a.second,a.first));
        }
        while(!pq.empty()){
            int freq = pq.top().first;
            int val = pq.top().second;
            for(int i =0; i < freq;++i)
                ans += val;
            pq.pop();
        }
        return ans;
    }
};
