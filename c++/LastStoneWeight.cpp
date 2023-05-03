class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //We can just use a heap for this
        priority_queue<int> pq;
        for(int i =0; i < stones.size();++i)
            pq.push(stones[i]);
        while(pq.size() > 1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if(x != y)
                pq.push(y - x);
        }
        return !pq.empty() ? pq.top() : 0;
    }
};
