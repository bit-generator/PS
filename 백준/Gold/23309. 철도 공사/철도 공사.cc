#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

constexpr size_t MAX_SIZE = 2'000'001;
int N, M, P, Q;
string cmd;

struct Node {
    int id;
    Node* prev;
    Node* next;
} nodepool[MAX_SIZE];

int nodeCnt;
unordered_map<int, Node*> stn;

Node* makeNode(int id) {
    nodepool[nodeCnt].id = id;
    return &nodepool[nodeCnt++];
}

class LinkedList {
    Node* tail;
public:
    LinkedList() {
        this->tail = nullptr;
    }
    
    void push_back(int id) {
        Node* newNode = makeNode(id);
        
        if(this->tail == nullptr) {
            this->tail = newNode;
            newNode->prev = newNode;
            newNode->next = newNode;
        }
        else {
            newNode->prev = this->tail;
            newNode->next = this->tail->next;
            this->tail->next = newNode;
            newNode->next->prev = newNode;
            this->tail = newNode;
        }
        
        stn[id] = newNode;
    }
    
    void push_back(int i, int j) {
        Node* newNode = makeNode(j);
        Node* cur = stn[i];
        
        newNode->prev = cur;
        newNode->next = cur->next;
        newNode->prev->next = newNode;
        newNode->next->prev = newNode;
        
        stn[j] = newNode;
    }
    
    void push_front(int i, int j) {
        Node* newNode = makeNode(j);
        Node* cur = stn[i];
        
        newNode->prev = cur->prev;
        newNode->next = cur;
        newNode->prev->next = newNode;
        newNode->next->prev = newNode;
        
        stn[j] = newNode;
    }
    
    int pop_back(int i) {
        Node* cur = stn[i]->next;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        return cur->id;
    }
    
    int pop_front(int i) {
        Node* cur = stn[i]->prev;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        return cur->id;
    }
};
LinkedList llist;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    while(N--) {
        cin >> P;
        llist.push_back(P);
    }
    
    while(M--) {
        cin >> cmd;
        if(cmd == "BN") {
            cin >> P >> Q;
            cout << stn[P]->next->id << '\n';
            llist.push_back(P, Q);
        }
        else if(cmd == "BP") {
            cin >> P >> Q;
            cout << stn[P]->prev->id << '\n';
            llist.push_front(P, Q);
        }
        else if(cmd == "CN") {
            cin >> P;
            cout << llist.pop_back(P) << '\n';
        }
        else {
            cin >> P;
            cout << llist.pop_front(P) << '\n';
        }
    }
    
    return 0;
}