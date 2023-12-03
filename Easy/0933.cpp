class RecentCounter {
public:
    std::queue<long long> pingerlol;


    RecentCounter() {
    }
    
    int ping(int t) {
        std::ios_base::sync_with_stdio(false);
        this->pingerlol.push(t);
        while(this->pingerlol.front()<t-3000){
            this->pingerlol.pop();
        }
        return this->pingerlol.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */