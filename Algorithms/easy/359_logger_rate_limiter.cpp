/**
    359. Logger Rate Limiter
Design a logger system that receive stream of messages along with its timestamps, 
each message should be printed if and only if it is not printed in the last 10 seconds.

Given a message and a timestamp (in seconds granularity), 
return true if the message should be printed in the given timestamp, otherwise returns false.

It is possible that several messages arrive roughly at the same time.

Example:
Logger logger = new Logger();

// logging string "foo" at timestamp 1
logger.shouldPrintMessage(1, "foo"); returns true; 

// logging string "bar" at timestamp 2
logger.shouldPrintMessage(2,"bar"); returns true;

// logging string "foo" at timestamp 3
logger.shouldPrintMessage(3,"foo"); returns false;

// logging string "bar" at timestamp 8
logger.shouldPrintMessage(8,"bar"); returns false;

// logging string "foo" at timestamp 10
logger.shouldPrintMessage(10,"foo"); returns false;

// logging string "foo" at timestamp 11
logger.shouldPrintMessage(11,"foo"); returns true;

Algo1: naive: use dict
dict[msg]->time

Algo2: dict with iterators on deque with all data
struct event:
    time
    msg
deque<event>
*/

class Logger {
    static constexpr int TIME_THRES = 10;
public:
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, const string& message) {
        if (msg_time.count(message)) {
            int last_time = msg_time[message];
            if (timestamp - last_time >= TIME_THRES) {
                msg_time[message] = timestamp;
                return true;
            } else {
                return false;
            }
        } else {
            msg_time[message] = timestamp;
            return true;
        }
    }
    
private:
    unordered_map<string, int> msg_time;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

class Logger {
    static constexpr int TIME_THRES = 10;
    
    struct Event {
        int time = 0;
        string msg;
    };
    
    using Iterator = deque<Event>::iterator;
public:
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int now, const string& message) {
        shrink(now);
        if (msg_time.count(message)) {
            int last_time = getTime(message);
            if (now - last_time >= TIME_THRES) {
                deleteEvent(message);
                addEvent(message, now);
                return true;
            } else {
                return false;
            }
        } else {
            addEvent(message, now);
            return true;
        }
    }
    
private:
    deque<Event> data;
    unordered_map<string, Iterator> msg_time;
    
    int getTime(const string& msg) const {
        auto it = msg_time.at(msg);
        return it->time;
    }
    
    void deleteEvent(const string& msg)  {
        //auto it = msg_time[msg];
        //it->msgs.erase(msg);
        msg_time.erase(msg);
        // msgs.empty()?
    }
    
    void addEvent(const string& message, int time) {
        data.push_back(Event{time, message});
        msg_time[message] = prev(data.end());
    }
    
    void shrink(int time) {
        while (!data.empty() && data.front().time + TIME_THRES < time) {
            msg_time.erase(data.front().msg);
            data.pop_front();
        }
    }
};

class Logger {
    static constexpr int TIME_THRES = 10;
    
    struct Event {
        int time = 0;
        string msg;
    };
    
    using Iterator = list<Event>::iterator;
public:
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int now, const string& message) {
        shrink(now);
        if (msg_time.count(message)) {
            int last_time = getTime(message);
            if (last_time + TIME_THRES <= now) {
                deleteEvent(message);
                addEvent(message, now);
                return true;
            } else {
                return false;
            }
        } else {
            addEvent(message, now);
            return true;
        }
    }
    
private:
    list<Event> data;
    unordered_map<string, Iterator> msg_time;
    
    int getTime(const string& msg) const {
        auto it = msg_time.at(msg);
        return it->time;
    }
    
    void deleteEvent(const string& msg)  {
        auto it = msg_time[msg];
        data.erase(it);
        msg_time.erase(msg);
    }
    
    void addEvent(const string& message, int time) {
        msg_time[message] = data.insert(data.end(), Event{time, message});
    }
    
    void shrink(int time) {
        while (!data.empty() && data.front().time + TIME_THRES <= time) {
            msg_time.erase(data.front().msg);
            data.pop_front();            
        }
    }
};