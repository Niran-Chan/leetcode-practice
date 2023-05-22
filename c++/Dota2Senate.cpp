class Solution {
public:
    string predictPartyVictory(string senate) {
        /*
            Strategy is to keep banning the next senator that does not 
belong in the current party
        Ideally, u want to block whats in front so that they have no 
voting rights this round
        */
        queue <int> q1;
        queue <int> q2;
        int n = senate.size();
        for(int i =0; i < senate.size();++i){
            if(senate[i] == 'D')
                q1.push(i);
            else 
                q2.push(i);
                }
        while(!q1.empty() && !q2.empty()){
            int q1Idx = q1.front(),q2Idx = q2.front();
            q1.pop(),q2.pop();
            if(q1Idx < q2Idx)
                q1.push(q1Idx + n);
            else
                q2.push(q2Idx + n);
        }
        if(q1.empty())
            return "Radiant";
        return "Dire";

    }
};
