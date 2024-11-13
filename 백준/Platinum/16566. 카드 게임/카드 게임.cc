#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K, A;
bool isExist[4000001];
int parent[4000001];
vector<int> cards;

int find(int x) {
    if(x == parent[x]) return x;
    return x = find(parent[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++) {
        cin >> A;
        isExist[A] = true;
    }
    
    for(int i = 1; i <= N; i++) {
        if(isExist[i]) cards.push_back(i);
        parent[i] = i;
    }
    
    while(K--) {
        cin >> A;
        int idx = upper_bound(cards.begin(), cards.end(), A) - cards.begin();
        int trueIdx = find(idx);
        cout << cards[trueIdx] << '\n';
        parent[trueIdx] = trueIdx + 1;
    }
    
    return 0;
}