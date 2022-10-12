class Solution {
public:
    int minSetSize(vector<int>& arr) {
        //Generate max heap, and use hashtable to calculate the remaining amount
        
        unordered_map<int,int> freq;
        priority_queue <pair<int,int>> pq;
        for(int i = 0 ; i < arr.size();i++)
                freq[arr[i]]++;
        for(auto it: freq)
            pq.push(make_pair(it.second,it.first));
        int n = arr.size();
        int target = arr.size()/2;
        vector <int> output;
        while(target < n && !pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            n -= top.first;
            output.push_back(top.second);
            
        }
        return output.size();
        
    }
};
