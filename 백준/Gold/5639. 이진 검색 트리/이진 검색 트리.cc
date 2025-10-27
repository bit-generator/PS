#include <iostream>
using namespace std;

struct Node {
    int num;
    Node* l;
    Node* r;
} nodepool[10000];
int nodecnt;

int N;
Node* root = &nodepool[0];

void insert(int n) {
    Node* cur = root;
    while(cur->num != 0) {
        if(n < cur->num) {
            if(cur->l == nullptr) cur->l = &nodepool[++nodecnt];
            cur = cur->l;
        }
        else {
            if(cur->r == nullptr) cur->r = &nodepool[++nodecnt];
            cur = cur->r;
        }
    }
    
    cur->num = n;
}

void postorder(Node* cur) {
    if(cur == nullptr) return;
    postorder(cur->l);
    postorder(cur->r);
    cout << cur->num << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(cin >> N) {
        insert(N);
    }
    
    postorder(root);
    return 0;
}