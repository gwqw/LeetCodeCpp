/**
    381. Insert Delete GetRandom O(1) - Duplicates allowed
Implement the RandomizedCollection class:

RandomizedCollection() Initializes the RandomizedCollection object.
bool insert(int val) Inserts an item val into the multiset if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the multiset if present. Returns true if the item was present, false otherwise. Note that if val has multiple occurrences in the multiset, we only remove one of them.
int getRandom() Returns a random element from the current multiset of elements (it's guaranteed that at least one element exists when this method is called). The probability of each element being returned is linearly related to the number of same values the multiset contains.
You must implement the functions of the class such that each function works in average O(1) time complexity.

Example 1:
Input
["RandomizedCollection", "insert", "insert", "insert", "getRandom", "remove", "getRandom"]
[[], [1], [1], [2], [], [1], []]
Output
[null, true, false, true, 2, true, 1]

Explanation
RandomizedCollection randomizedCollection = new RandomizedCollection();
randomizedCollection.insert(1);   // return True. Inserts 1 to the collection. Returns true as the collection did not contain 1.
randomizedCollection.insert(1);   // return False. Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
randomizedCollection.insert(2);   // return True. Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
randomizedCollection.getRandom(); // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
randomizedCollection.remove(1);   // return True. Removes 1 from the collection, returns true. Collection now contains [1,2].
randomizedCollection.getRandom(); // getRandom should return 1 and 2 both equally likely.
 
Constraints:
-2^31 <= val <= 2^31 - 1
At most 2 * 10^5  calls will be made to insert, remove, and getRandom.
There will be at least one element in the data structure when getRandom is called.

Algo: same as wo repeat, dict[value]->set(vector_idx)
insert:
    data.push_back(value)
    dict[value].insert(data.size())
    return dict[value].size() > 1

remove(value):
    if value not in dict: return false
    idx = dict[value].pop_one()
    if dict[value].empty(): dict.erase(value)
    if (idx+1 == data.size()) {
        data.clear()
        return true
    }
    swap(data[idx], data.back())
    data.pop_back();
    prev_idx = data.size()
    new_value = data[idx]
    dict[new_value].remove(prev_idx)
    dict[new_value].insert(idx)
    return true
    
getRandom():
    idx = rand() % data.size()
    return data[idx]

*/

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        data.push_back(val);
        dict[val].insert(data.size()-1);
        return dict[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!dict.count(val)) return false;
        // extract idx from set
        size_t idx = *dict[val].begin();
        dict[val].erase(idx);
        if (dict[val].empty()) dict.erase(val);
        // remove val from data (swap with last)
        if (idx+1 == data.size()) {
            data.pop_back();
            return true;
        }
        swap(data[idx], data.back());
        data.pop_back();
        // update dict for swapped element
        val = data[idx];
        size_t prev_idx = data.size();
        dict[val].erase(prev_idx);
        dict[val].insert(idx);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        size_t idx = rand() % data.size();
        return data[idx];
    }
    
private:
    unordered_map<int, unordered_set<size_t>> dict;
    vector<int> data;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
