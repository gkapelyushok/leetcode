class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (ids.count(val)) {
            return false;
        }
        ids[val] = vals.size();
        vals.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!ids.count(val)) {
            return false;
        }
        int id = ids[val];
        ids[vals[vals.size() - 1]] = id;
        ids.erase(val);
        vals[id] = vals[vals.size() - 1];
        vals.pop_back();
        return true;
    }
    
    int getRandom() {
        return vals[rand() % vals.size()];
    }
private:
    unordered_map<int, int> ids;
    vector<int> vals;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */