/**
    460. LFU Cache
Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

Note that the number of times an item is used is the number of calls to the get and put functions for that item since it was inserted. This number is set to zero when the item is removed.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LFUCache cache = new LFUCache( 2 ); // capacity

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.get(3);       // returns 3.
cache.put(4, 4);    // evicts key 1.
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

Algo:
dict1[key] -> list::iter
dict2[freq]->list<Event>
size, capacity
min_freq = 0

get(key):
- if key not in d1: return -1
- Event e = popEvent:
    - it = d1[key]
    - Event e = *it
    - d2[e.freq].erase(it)
    - if d2[e.freq].empty(): 
        - d2.erase(freq)
        - if freq == min_freq:
            - min_freq = freq+1
- e.freq++
- pushEvent:
    - d2[e.freq].push_back(e)
    - d1[key] = it from d2
- return e.value

put(key, value):
- if size == capacity:
    - remove_lfu()
- Event e = key in d1 ? popEvent : {key, value, 1}
- e.value = value
- pushEvent:
- ++size
- if min_freq == 0:
    min_freq = 1

remove_lfu():
    e = d2[min_freq].front()
    d1.erase(e.key)
    d2[min_freq].pop_front()
    if d2[min_freq].empty() {
        d2.erase(min_freq)
        min_freq = 0
    }
*/

class LFUCache {
    struct Event {
        int key;
        int value = 0;
        int freq = 0;
    };
    using Iterator = list<Event>::iterator;
    
public:
    LFUCache(int capacity) : capacity(capacity)
    {}

    int get(int key) {
        if (!d1.count(key)) return -1;
        auto e = popEvent(key);
        ++e.freq;
        pushEvent(e);
        return e.value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        Event e{key, value, 1};
        if (d1.count(key)) {
            e = popEvent(key);
            ++e.freq;
            e.value = value;
        } else {
            if (d1.size() == capacity) {
                removeLFU();
                if (min_freq == 0) {
                    min_freq = 1;
                }
            }
            if (min_freq > 1) min_freq = 1;
        }
        pushEvent(e);
    }
    
private:
    size_t capacity = 0;
    int min_freq = 1;
    unordered_map<int, Iterator> d1;
    unordered_map<int, list<Event>> d2;
    
    Event popEvent(int key) {
        auto it = d1[key];
        Event e = *it;
        d2[e.freq].erase(it);
        if (d2[e.freq].empty()) {
            d2.erase(e.freq);
            if (e.freq == min_freq) {
                ++min_freq;
            }
        }
        return e;
    }
    
    void pushEvent(Event e) {
        auto it = d2[e.freq].insert(d2[e.freq].end(), e);
        d1[e.key] = it;
    }
    
    void removeLFU() {
        auto e = d2[min_freq].front();
        d1.erase(e.key);
        d2[min_freq].pop_front();
        if (d2[min_freq].empty()) {
            d2.erase(min_freq);
            min_freq = 0;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
 /*
["LFUCache","put","put","get","put","get","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]] 
 */