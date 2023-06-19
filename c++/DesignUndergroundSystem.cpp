class UndergroundSystem {
public:
    //ID will help to keep track of correct timings from the stations
    //station names and timings are relevant to their own node and they 
beloing in the subnet of the ID
    //Hashtable tells me which IDs have the particular stations i am 
looking for
    unordered_map<int,pair<string,int>>mp1;
    unordered_map<string,pair<int,int>> mp2;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp1[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,int> p1 = mp1[id];
        mp1.erase(id);
        string rt = p1.first + "_" + stationName;
        mp2[rt].first += t - p1.second;
        mp2[rt].second++;

    }
    
    double getAverageTime(string startStation, string endStation) {
       string rt = startStation + "_" + endStation;
       pair<int,int> time = mp2[rt];
       return (double)time.first/time.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
