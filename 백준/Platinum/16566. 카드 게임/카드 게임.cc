#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K, A;
int cards[4000000];
int parent[4000000];

int find(int x) {
    if(x == parent[x]) return x;
    return x = find(parent[x]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    
    if(a < b) parent[a] = b;
    else parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++) {
        cin >> cards[i];
        parent[cards[i]] = cards[i];
    }
    sort(cards, cards + M);
    for(int i = 0; i < M; i++) {
        parent[i] = i;
    }
    
    while(K--) {
        cin >> A;
        int idx = upper_bound(cards, cards + M, A) - cards;
        int trueIdx = find(idx);
        cout << cards[trueIdx] << '\n';
        if(trueIdx != M - 1) Union(trueIdx, trueIdx + 1);
    }
    
    return 0;
}