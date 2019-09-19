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

/// O(N) + O(N)
void remove_duplicates(Node* head) {
    if (!head) return;

    Node* n = head;
    unordered_set<int> buffer;
    buffer.insert(n->value);

    while (n && n->next) {
        if (buffer.count(n->next->value)) {
            Node* tmp = n->next;
            n->next = n->next->next;
            delete tmp;
        } else {
            buffer.insert(n->next->value);
            n = n->next;
        }
    }
    return;
}

///O(N^2) + O(1)
Node* remove_duplicates2(Node* head) {
    if (!head) return head;

    Node* prev = nullptr;
    Node* n = head;
    while (n) {
        Node* runner = n->next;
        bool is_found = false;
        while (runner) {
            if (runner->value == n->value) {
                is_found = true;
                break;
            }
            runner = runner->next;
        }
        if (is_found) {
            Node* tmp = n;
            if (prev) {
                prev->next = n->next;
                n = n->next;
            } else {
                head = n->next;
                n = n->next;
            }
            delete tmp;
        } else {
            prev = n;
            n = n->next;
        }
    }
    return head;
}