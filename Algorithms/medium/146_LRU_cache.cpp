/**
   146. LRU Cache
Design and implement a data structure for Least Recently Used (LRU) cache.
It should support the following operations: get and put.
- get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
- put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:
LRUCache cache = new LRUCache( 2  [capacity]  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

Algo:
dict[key] -> list_iterator
list: [] - [] - []. node: value

get(key):
    if no: return -1
    it <- dict[key]
    res = it->value
    promote(it):
        lst.erase(it)
        it = lst.insert(lst.end(), res)
        dict[key] = it
    return res
    
put(key, value):
    if key in dict:
        it <- dict[key]
        it->value = value
        promote(it)
    else:
        if size == max_size:
            shrink_list
        it <- lst.insert(lst.end(), value)
        dict[key] = it   
        
    
*/

class LRUCache {
    using Iterator = list<pair<int, int>>::iterator;
public:
    LRUCache(int capacity) : capacity(capacity) 
    {
        assert(capacity > 0);
    }
    
    int get(int key) {
        if (!dict.count(key)) return -1;
        auto& it = dict[key];
        int res = it->second;
        it = promote(it);
        return res;
        
    }
    
    void put(int key, int value) {
        if (dict.count(key)) {
            auto& it = dict[key];
            it->second = value;
            it = promote(it);
        } else {
            if (lst.size() == capacity) {
                dict.erase(lst.begin()->first);
                lst.erase(lst.begin());
            }
            auto it = lst.insert(lst.end(), {key, value});
            dict.emplace(key, it);
        }
    }
private:
    int capacity = 0;
    unordered_map<int, Iterator> dict;
    list<pair<int, int>> lst;
    
    Iterator promote(Iterator it) {
        auto kv = *it;
        lst.erase(it);
        it = lst.insert(lst.end(), kv);
        return it;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
 
 /*
 ["LRUCache","put","put","get","put","get","get"]
[[2],[2,1],[1,1],[2],[4,1],[1],[2]]
 
 
 */
