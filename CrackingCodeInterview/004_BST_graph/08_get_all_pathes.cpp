/**
You are given a binary tree in which each node contains a value. 
Design an algorithm to print all paths which sum up to that value. 
Note that it can be any path in the tree - it does not have to start at the root.

Algo1 - simplified: paths from the root
sum += node.value
if sum == requested: store sum
calc_sum(left, sum, req_sum, cur_path, paths_lst)

Algo2 - sum from any place
go through nodes
from each node go up and substract from req_sum node.value
    if we get 0: push to PathLst
go to the left
go to the right
*/

#include <stack>
#include <vector>

struct Node {
    int value = 0;
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;    
};

using Path = std::vector<Node*>;
using PathLst = std::vector<Path>;

class SumPathFinderFromRoot {
public:
    const PathLst& find_sum_list(int req_sum, Node* root) {
        req_sum_ = req_sum;
        Path p;
        path_lst_.clear();
        calc_sum_res(root, 0, p);
        return path_lst_;
    }
private:
    int req_sum_ = 0;
    PathLst path_lst_;
    
    void calc_sum_rec(Node* node, int sum, Path cur_path) {
        if (!node) return;
        sum += node->value;
        cur_path.push_back(node);
        if (sum == req_sum_) {
            path_lst_.push_back(cur_path);
        }
        calc_sum_rec(node->left, sum, cur_path);
        calc_sum_rec(node->right, sum, cur_path);
    }
}

class SumPathFinder {
public:
    const PathLst& find_sum_list(int req_sum, Node* root) {
        req_sum_ = req_sum;
        Path p;
        path_lst_.clear();
        calc_sum_res(root, p);
        return path_lst_;
    }
private:
    int req_sum_ = 0;
    PathLst path_lst_;
    
    void calc_sum_rec(Node* node, Path cur_path) {
        if (!node) return;
        
        int sum = req_sum_;
        for (auto it = rbegin(cur_path); it != rend(cur_path); ++it) {
            sum -= (*it)->value;
            if (sum == 0) {
                path_lst_.push_back(Path{it, end(cur_path)});
            }
        }
        
        cur_path.push_back(node);
        calc_sum_rec(node->left, cur_path);
        calc_sum_rec(node->right, cur_path);
    }
}