class Solution {
public:

 struct Compare {
    bool operator() (pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        priority_queue<pair<int,string>,vector<pair<int,string>>,Compare> pq;
        for(int i =0; i < words.size();i++)
        {
            mp[words[i]]++;
        }      
        for(auto it : mp)
        {
            pq.push({it.second,it.first});
        }

        vector<string> res;
        for(int i =0; i < k;i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    
    }

};
