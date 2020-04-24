/**
    432. All O`one Data Structure
Implement a data structure supporting the following operations:
- Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
- Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
- GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
- GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
Challenge: Perform all these in O(1) time complexity.

Algo:
sorted list with value and unordered_set of keys
dict[key]->list::iterator
    
inc:
- if key doesn't exist: value = 1
    - if begin->value == 1:
        - insert key here
    - else:
        - insert node here with value 1 and {1}
- else:
    - remove value-key from list (and remove node if empty)
    ++value
    - and insert after (if node !exists: create it)
    - update iterator in dict
- getMaxKey:
    - get max key from end of list
    
*/

class AllOne {

    struct Node {
        int value = 1;
        unordered_set<string> keys;
    };
    
    using Iterator = list<Node>::iterator;

public:
    /** Initialize your data structure here. */
    AllOne() 
    {}
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(const string& key) {
        int value = 1;
        auto it = lst.begin();
        if (dict.count(key)) {
            it = dict[key];
            value = it->value + 1;
            it->keys.erase(key);
            if (it->keys.empty()) {
                it = lst.erase(it);
            } else {
                it = next(it);
            }            
        }
        it = insert(it, key, value);
        dict[key] = it;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(const string& key) {
        if (!dict.count(key)) return;
        auto it = dict[key];
        auto value = it->value - 1;
        it->keys.erase(key);
        if (it->keys.empty()) {
            it = lst.erase(it);
        }
        if (it != lst.begin() && value <= prev(it)->value) {
            it = prev(it);
        }
        if (value != 0) {
            it = insert(it, key, value);
            dict[key] = it;
        } else {
            dict.erase(key);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() const {
        if (lst.empty()) {
            return "";
        } else {
            auto it = prev(lst.end());
            return *(it->keys.begin());
        }
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() const {
        if (lst.empty()) {
            return "";
        } else {
            auto it = lst.begin();
            return *(it->keys.begin());
        }
    }
private:
    list<Node> lst;
    unordered_map<string, Iterator> dict;
    
    Iterator remove(Iterator it, const string& key) {
        it->keys.erase(key);
        if (it->keys.empty()) {
            it = lst.erase(it);
        }
        return it;
    }
    
    Iterator insert(Iterator it, const string& key, int value) {
        if (it == lst.end() || it->value != value) {
            assert(it == lst.end() || value < it->value);
            return lst.insert(it, Node{value, {key}});
        } else {
            it->keys.insert(key);
            return it;
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
