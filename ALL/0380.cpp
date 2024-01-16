class RandomizedSet {
public:
    std::unordered_set<int> set;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(set.find(val) != set.end()){
            return 0;
        }
        set.insert(val);
        return 1;
    }
    
    bool remove(int val) {
        if(set.find(val) == set.end()){
            return 0;
        }
        set.erase(set.find(val));
        return 1;
    }
    
    int getRandom() {
        return *next(set.begin(), (rand() % set.size()));
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */