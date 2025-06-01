#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

constexpr size_t MAX_SIZE = 100001;
int N;
string cmd;

struct Node {
    int idx;
    int len;
    Node* next;
    Node* prev;
} nodepool[MAX_SIZE];
int nodeCnt;
unordered_map<string, Node*> vars;

Node* makeNode(int idx, int len) {
    nodepool[nodeCnt].idx = idx;
    nodepool[nodeCnt].len = len;
    return &nodepool[nodeCnt++];
}

class LinkedList {
    int size;
    Node* head;
public:
    LinkedList() {
        this->head = makeNode(1, 0);
        this->size = 0;
    }

    Node* insert(Node* pos, int len) {
        Node* newNode = makeNode(pos->idx + pos->len, len);
        newNode->next = pos->next;
        newNode->prev = pos;
        pos->next = newNode;
        if (newNode->next != nullptr) newNode->next->prev = newNode;
        ++this->size;

        return newNode;
    }

    void remove(Node* pos) {
        pos->prev->next = pos->next;
        if (pos->next != nullptr) pos->next->prev = pos->prev;
        --this->size;
    }

    Node* findSpaceNode(int sz) {
        if (this->size == 0) return this->head;
        Node* cur = this->head;

        while (cur != nullptr) {
            int nxtIdx = (cur->next == nullptr ? MAX_SIZE : cur->next->idx);
            int spaceSize = nxtIdx - (cur->idx + cur->len);
            if (spaceSize >= sz) {
                return cur;
            }

            cur = cur->next;
        }

        return nullptr;
    }
};
LinkedList llist;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    while (N--) {
        cin >> cmd;
        if (cmd.find("malloc") != string::npos) {
            string name = cmd.substr(0, 4);
            int lpos = cmd.find('(');
            int rpos = cmd.find(')');
            int sz = stoi(cmd.substr(lpos + 1, rpos - lpos - 1));

            Node* spaceNode = llist.findSpaceNode(sz);
            vars[name] = nullptr;
            if (spaceNode != nullptr) vars[name] = llist.insert(spaceNode, sz);
        }
        else if (cmd.find("free") != string::npos) {
            int lpos = cmd.find('(');
            string name = cmd.substr(lpos + 1, 4);

            if (vars[name] != nullptr) llist.remove(vars[name]);
            vars[name] = nullptr;
        }
        else {
            int lpos = cmd.find('(');
            string name = cmd.substr(lpos + 1, 4);

            if (vars[name] == nullptr) cout << 0 << '\n';
            else cout << vars[name]->idx << '\n';
        }
    }

    return 0;
}