class BrowserHistory {
public:
    //Current instance properties
    list <string> history;
    list<string> ::iterator currPage = history.begin();

    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currPage++;
    }
    
    void visit(string url) {
        auto tmp = currPage;
        tmp ++;
        history.erase(tmp, history.end());
        history.push_back(url);
        currPage++;
    }
    
    string back(int steps) {
        while(currPage!=(history.begin())&& steps--) {
            currPage--;
        }
        return *currPage;
    }
    
    string forward(int steps) {
        while(currPage!=(--history.end())&& steps--) {
            currPage++;
        }
        return *currPage;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
