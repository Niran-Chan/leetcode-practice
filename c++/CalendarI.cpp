//Vector pair method
class MyCalendar {
public:
    MyCalendar() {
 
    }
           vector<pair<int,int>> grid;
    bool book(int start, int end) {
        for(int i = 0;i < grid.size();i++ )
        {
            if( !(grid[i].second< start || end-1 < grid[i].first ))
                    return false;                           
        }
        grid.push_back({start,end-1});
        sort(grid.begin(),grid.end());
	return true;
    }
};
//map method, which is faster but less memory optimisation
class MyCalendar {
    map<int, int> mp;   // <endTime, statIme>
public:  
    bool book(int start, int end) {
        /*lookfor first endTIme that is larger than start time request. First condition checkes 
if the incoming request should be added to the list of booked slots.*/
        auto itr = mp.upper_bound(start);
        if(itr == mp.end() || end<= itr->second) {
            mp[end]=start;
            return true;
        } 
        else  return false;
    }
};



