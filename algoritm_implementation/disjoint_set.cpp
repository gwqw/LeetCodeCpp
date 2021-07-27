#include <vector>
#include <iostream>

using namespace std;

class DisjointSet {
public:
    DisjointSet(size_t max_size) 
        : parent(max_size, -1), rank(max_size, -1)
    {}
    
    void makeSet(int i) {
        resize(i+1);
        parent[i] = i;
        rank[i] = 0;
    }
    
    int find(int i) {
        if (i != parent[i]) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
    
    void unionSets(int i, int j) {
        int i_id = find(i);
        int j_id = find(j);
        if (i_id == j_id) return;
        if (rank[i_id] >= rank[j_id]) {
            parent[j_id] = i_id;
            if (rank[i_id] == rank[j_id]) {
                ++rank[i_id];
            }
        } else {
            parent[i_id] = j_id;
        }
    }
    
    void print(ostream& out) {
        out << "parent: ";
        for (int i : parent) {
            out << i << " ";
        }
        out << '\n';
        out << "rank: ";
        for (int i : rank) {
            out << i << " ";
        }
        out << '\n';
    }
    
    
private:
    void resize(size_t new_size) {
        if (parent.size() < new_size) {
            new_size += new_size - parent.size();
            parent.resize(new_size);
            rank.resize(new_size);
        }
    }
    
private:
    vector<int> parent;1 2 3 2 5 
    vector<int> rank;
};


int main() {
    DisjointSet st(7);
    st.makeSet(1);
    st.makeSet(2);
    st.makeSet(3);
    st.makeSet(4);
    st.makeSet(5);
    st.makeSet(6);
    st.print(cout);
    st.unionSets(2,4);
    st.print(cout);
    st.unionSets(5,2);
    st.print(cout);
    st.unionSets(3,1);
    st.print(cout);
    st.unionSets(2,3);
    st.print(cout);
    st.unionSets(2,6);
    st.print(cout);
}