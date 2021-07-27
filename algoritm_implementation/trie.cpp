#include <unordered_map>
#include <string>
#include <string_view>

class Trie {
    struct Node;
    
    using NodePtr = Node*;
    
    struct Node {
        string prefix;
        bool is_leaf = true;
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
        word.remove_prefix(node->prefix.size());
        if (word.empty()) return node->is_leaf;
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
        prefix.remove_prefix(node->prefix.size());
        return startsWith(node->children[prefix[0]], prefix);
    }
    
    static void insert(NodePtr& node, string_view word) {
        if (!node) {
            node = new Node{string(word), true};
            return;
        }
        if (isPrefix(word, node->prefix)) {
            word.remove_prefix(node->prefix.size());
            if (word.empty()) {
                node->is_leaf = true;
                return;
            }
            insert(node->children[word[0]], word);
            return;
        }
        // split prefix and word at common prefix and wordSuffix and nodeSuffix
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