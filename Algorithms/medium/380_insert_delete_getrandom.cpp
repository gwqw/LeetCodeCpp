/**
    380. Insert Delete GetRandom O(1)
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();


Algo: use vector and dict[value]->idx
*/

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        data.reserve(9000);
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (data_idx.count(val) != 0) return false;
        data.push_back(val);
        data_idx[val] = data.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (data_idx.count(val) == 0) return false;
        size_t idx = data_idx[val];
        if (idx+1 != data.size()) {
            int swap_val = data.back();
            swap(data[idx], data.back());
            data_idx[swap_val] = idx;
        } 
        data.pop_back();
        data_idx.erase(val);            
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        //size_t idx = rand() /((1u + RAND_MAX) / data.size());
        if (data_idx.empty()) {
            throw invalid_argument("Set is empty");
        }
        size_t idx = rand() % data.size();
        auto it = data.begin() + idx;
        return *it;
    }
private:
    vector<int> data;
    unordered_map<int, size_t> data_idx;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
