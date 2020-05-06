/**
    1166. Design File System
You are asked to design a file system which provides two functions:

createPath(path, value): Creates a new path and associates a value to it if possible and returns True. Returns False if the path already exists or its parent path doesn't exist.
get(path): Returns the value associated with a path or returns -1 if the path doesn't exist.
The format of a path is one or more concatenated strings of the form: / followed by one or more lowercase English letters. For example, /leetcode and /leetcode/problems are valid paths while an empty string and / are not.
Implement the two functions.

Please refer to the examples for clarifications.

Example 1:
Input: 
["FileSystem","createPath","get"]
[[],["/a",1],["/a"]]
Output: 
[null,true,1]
Explanation: 
FileSystem fileSystem = new FileSystem();
fileSystem.createPath("/a", 1); // return true
fileSystem.get("/a"); // return 1

Example 2:
Input: 
["FileSystem","createPath","createPath","get","createPath","get"]
[[],["/leet",1],["/leet/code",2],["/leet/code"],["/c/d",1],["/c"]]
Output: 
[null,true,true,2,false,-1]
Explanation: 
FileSystem fileSystem = new FileSystem();

fileSystem.createPath("/leet", 1); // return true
fileSystem.createPath("/leet/code", 2); // return true
fileSystem.get("/leet/code"); // return 2
fileSystem.createPath("/c/d", 1); // return false because the parent path "/c" doesn't exist.
fileSystem.get("/c"); // return -1 because this path doesn't exist.

Constraints:
The number of calls to the two functions is less than or equal to 10^4 in total.
2 <= path.length <= 100
1 <= value <= 10^9
NOTE: create method has been changed on August 29, 2019 to createPath. Please reset to default code definition to get new method signature.

Algo:
use dict of dicts:

*/

class FileSystem {
    struct Node;
    using NodeHolder = unique_ptr<Node>;
    struct Node {
        int value = -1;
        unordered_map<string, NodeHolder> children;
    };
public:
    bool createPath(string_view path, int value) {
        return createPathRec(root, path, value);
    }
    
    int get(const string& path) const {
        return getRec(root, path);
    }
private:
    NodeHolder root;
    
    static string_view getWord(string_view& path) {
        auto pos = path.find('/');
        if (pos == string_view::npos) {
            pos = path.size();
        }
        string_view res = path.substr(0, pos);
        path.remove_prefix(pos);
        return res;
    }
    
    static bool createPathRec(NodeHolder& node, string_view path, int value) {
        string dir = string(getWord(path));
        if (!node) node = make_unique<Node>();
        if (path.empty() && node->children.count(dir)) return false;
        if (!node->children.count(dir)) {
            if (path.empty()) {
                node->children[dir] = make_unique<Node>(Node{value});
            } else {
                node->children[dir] = make_unique<Node>(Node{-1});
            }
        }
        if (path.empty()) {
            return true;
        } else {
            return createPathRec(node->children[dir], path, value);
        }        
    }
    
    static int getRec(const NodeHolder& node, string_view path) {
        string dir = string(getWord(path));
        if (!node->children.count(dir)) return -1;
        if (path.empty()) {
            return node->children.at(dir)->value;
        } else {
            return getRec(node->children.at(dir), path);
        }
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
