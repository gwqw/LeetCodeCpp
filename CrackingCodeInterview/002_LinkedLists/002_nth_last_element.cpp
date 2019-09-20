/**
    Implement an algorithm to find the nth to last element of a singly linked list
    Algo1:
    - count length -> m
    - go to m-1-n element from head (if counting from 0)
    O(N) + O(1)
    
    Algo2:
    - create window [p1, p2] with distance = n
    - move this window to the end, so p1 will be n-th last
    O(N) + O(1)
*/

struct Node {
    int value = 0;
    Node* next = nullptr;
};

std::ostream& operator<<(std::ostream& out, Node* n) {
    while (n) {
        out << n->value << " -> ";
        n = n->next;
    }
    out << "NULL";
    return out;
}

Node* get_nth_last(Node* head, size_t n) {
    // count length
    Node* p = head;
    size_t m = 0;
    while (p) {
        ++m;
        p = p->next;
    }
    // get n-th element from the end
    if (n+1 > m) throw invalid_argument("Not enough elements");
    for (size_t i = 0; i < m-n-1; ++i) {
        head = head->next;
    }
    return head;
}

Node* get_nth_last(Node* head, size_t n) {
    if (!head) return nullptr;
    Node* p1 = head;
    Node* p2 = head;
    // create window: move p2 on the n steps
    for (size_t i = 0; i < n; ++i) {
        if (p2) {
            p2 = p2->next;
        } else {
            return nullptr;
        }
    }
    while (p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}


