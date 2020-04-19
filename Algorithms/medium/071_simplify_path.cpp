/**
    71. Simplify Path
Given an absolute path for a file (Unix-style), simplify it.
Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. 
Furthermore, a double period .. moves the directory up a level.

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names.
The last directory name (if it exists) must not end with a trailing /. 
Also, the canonical path must be the shortest string representing the absolute path.

Example 1:
Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.

Example 2:
Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

Example 3:
Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

Example 4:
Input: "/a/./b/../../c/"
Output: "/c"

Example 5:
Input: "/a/../../b/../c//.//"
Output: "/c"

Example 6:
Input: "/a//b////c/d//././/.."
Output: "/a/b/c"

Algo: use stack for add path and remove
- go to next / and save line to the next slash (or the end)
- if string is empty or string == ".": continue
- if string is "..": remove from stack (if it is not empty)
- else: put string to stack
- after all form res: "/" + str from stack

*/

class Solution {
public:
    string simplifyPath(const string& path) {
        string cur;
        assert(!path.empty() && path[0] == '/');
        for (size_t i = 1; i < path.size(); ++i) {
            if (path[i] == '/') {
                if (cur.empty() || cur == ".") {
                } else if (cur == "..") {
                    if (!st.empty()) {
                        st.pop_back();
                    }
                } else {
                    st.push_back(move(cur));
                }
                cur.clear();
            } else {
                cur += path[i];
            }
        }
        if (cur == "..") {
            if (!st.empty()) {
                st.pop_back();
            }
        } else if (!cur.empty() && cur != ".") {
            st.push_back(move(cur));
        }
        string res;
        for (const auto& dir : st) {
            res += "/" + dir;
        }
        return !res.empty() ? res : "/";
    }
private:
    deque<string> st;
};