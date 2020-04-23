/**
    211. Add and Search Word - Data structure design
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. 
A . means it can represent any one letter.

Example:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note:
You may assume that all words are consist of lowercase letters a-z.


*/

class WordDictionary {
    struct Node;
    
    using NodePtr = Node*;
    
    struct Node {
        string prefix;
        bool isEnd = true;
        unordered_map<char, NodePtr> children;
    };
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(string_view word) {
        insert(root, word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string_view word) {
        return search(root, word);
    }

private:
    NodePtr root = nullptr;
    
    static bool search(NodePtr node, string_view word) {
        if (!node || word.size() < node->prefix.size() || !isPrefix(word, node->prefix)) {
            return false;
        }
        word = removePrefix(word, node->prefix);
        if (word.empty()) return node->isEnd;
        if (word[0] != '.') {
            return search(node->children[word[0]], word);
        } else {
            for (auto [_, node] : node->children) {
                if (search(node, word)) return true;
            }
            return false;
        }
    }
    
    static bool startsWith(NodePtr node, string_view prefix) {
        if (!node) {
            return false;
        }
        if (node->prefix.size() >= prefix.size()) {
            return isPrefix(node->prefix, prefix);
        }
        if (!isPrefix(prefix, node->prefix)) {
            return false;
        }
        assert(node->prefix.size() < prefix.size());
        prefix = removePrefix(prefix, node->prefix);
        assert(!prefix.empty());
        return startsWith(node->children[prefix[0]], prefix);
    }
    
    static void insert(NodePtr& node, string_view word) {
        if (!node) {
            node = new Node{string(word), true};
            return;
        }
        if (isPrefix(word, node->prefix)) {
            word = removePrefix(word, node->prefix);
            if (word.empty()) {
                node->isEnd = true;
                return;
            }
            insert(node->children[word[0]], word);
            return;
        }
        auto prefix = getCommonPrefix(word, node->prefix);
        auto nodeSuffix = removePrefix(node->prefix, prefix);
        auto wordSuffix = removePrefix(word, prefix);
        // node as child node
        {
            auto tmpNode = node;
            node = new Node{string(prefix), wordSuffix.empty()};
            tmpNode->prefix = string(nodeSuffix);
            node->children[tmpNode->prefix[0]] = tmpNode;           
        }
        // suff from word
        {            
            if (!wordSuffix.empty()) {
                node->children[wordSuffix[0]] = new Node{string(wordSuffix), true};
            }
        }
    }
    
    static bool isPrefix(string_view word, string_view prefix) {
        if (word.size() < prefix.size()) return false;
        for (size_t i = 0; i < prefix.size(); ++i) {
            if (word[i] != prefix[i] && word[i] != '.' && prefix[i] != '.') return false;
        }
        return true;
    }
    
    static string_view removePrefix(string_view word, string_view prefix) {
        assert(word.size() >= prefix.size());
        word.remove_prefix(prefix.size());
        return word;
    }
    
    static string_view getCommonPrefix(string_view lhs, string_view rhs) {
        size_t i = 0;
        for (; i < lhs.size() && i < rhs.size(); ++i) {
            if (lhs[i] != rhs[i]) break;
        }
        return lhs.substr(0, i);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */