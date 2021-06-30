/**
    981. Time Based Key-Value Store
Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
 

Example 1:
Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "ba2r" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"

Constraints:
1 <= key.length, value.length <= 100
key and value consist of lowercase English letters and digits.
1 <= timestamp <= 10^7
All the timestamps timestamp of set are strictly increasing.
At most 2 * 10^5 calls will be made to set and get.

Algo1: O(logN) for set and get
dict[key]->map[timestamp]->value
set(key, value, ts):
	dict[key][ts]=value
get(key, ts):
	mp = dict[key]
	it = mp.upper_bound(ts);
	if it == mp.begin(): return ""
	it = prev(it)
	return it->second
	
Algo2:
dict[key]->vector<int, string>
set:
    dict[key].push_back(t,v)
get:
    binary search for t in dict[key]

*/

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() 
	{}
    
    void set(string key, string value, int timestamp) {
        dict[move(key)][timestamp] = move(value);
    }
    
    string get(const string& key, int timestamp) {
        if (!dict.count(key)) return "";
		const auto& cont = dict.at(key);
		auto it = cont.upper_bound(timestamp);
		if (it == cont.begin()) return "";
		return prev(it)->second;
    }
	
private:
	unordered_map<string, map<int, string>> dict;
};

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() 
	{}
    
    void set(string key, string value, int timestamp) {
        dict[move(key)].emplace_back(timestamp, move(value));
    }
    
    string get(const string& key, int timestamp) {
        if (!dict.count(key)) return "";
		const auto& cont = dict.at(key);
		auto it = upper_bound(cont.begin(), cont.end(), timestamp, 
		    [](int value, const auto& element) {
		        return value < element.first;
		    }
	    );
		if (it == cont.begin()) return "";
		return prev(it)->second;
    }
	
private:
	unordered_map<string, vector<pair<int, string>>> dict;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
