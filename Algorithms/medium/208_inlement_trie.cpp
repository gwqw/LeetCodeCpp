/**
    208. Implement Trie (Prefix Tree)
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

class Trie {
    struct Node;
    
    using NodePtr = Node*;
    
    struct Node {
        string prefix;
        bool isEnd = true;
        unordered_map<char, NodePtr> children;
    };   

public:
    /** Initialize your data structure here. */
    Trie() 
    {}
    
    /** Inserts a word into the trie. */
    void insert(string_view word) {
        insert(root, word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string_view word) {
        return search(root, word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string_view prefix) {
        return startsWith(root, prefix);
    }
    
private:
    NodePtr root = nullptr;
    
    static bool search(NodePtr node, string_view word) {
        if (!node || word.size() < node->prefix.size() || !isPrefix(word, node->prefix)) {
            return false;
        }
        word = removePrefix(word, node->prefix);
        if (word.empty()) return node->isEnd;
        return search(node->children[word[0]], word);
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
            if (word[i] != prefix[i]) return false;
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

class Trie {
    struct Node;
    
    using NodePtr = Node*;
    
    template <typename T>
    struct CharMap {
        array<T, 26> data;
        T& operator[](char c) {
            assert('a' <= c && c <= 'z');
            return data[c-'a'];
        }
    };
    
    struct Node {
        string prefix;
        bool isEnd = true;
        CharMap<NodePtr> children;
    };   

public:
    /** Initialize your data structure here. */
    Trie() 
    {}
    
    /** Inserts a word into the trie. */
    void insert(string_view word) {
        insert(root, word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string_view word) {
        return search(root, word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string_view prefix) {
        return startsWith(root, prefix);
    }
    
private:
    NodePtr root = nullptr;
    
    static bool search(NodePtr node, string_view word) {
        if (!node || word.size() < node->prefix.size() || !isPrefix(word, node->prefix)) {
            return false;
        }
        word = removePrefix(word, node->prefix);
        if (word.empty()) return node->isEnd;
        return search(node->children[word[0]], word);
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
            if (word[i] != prefix[i]) return false;
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
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
 