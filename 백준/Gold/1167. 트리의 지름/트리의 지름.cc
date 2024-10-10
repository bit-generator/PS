#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int n, u, v, w, ans;
vector<pair<int, int>> tree[100001];

int dfs(int cur, int prv) {
    priority_queue<int> pq;
    for(auto p : tree[cur]) {
        int nxt = p.first;
        int weight = p.second;
        if(nxt == prv) continue;
        pq.push(dfs(nxt, cur) + weight);
    }
    
    if(pq.empty()) return 0;
    else if(pq.size() == 1) {
        int tmp = pq.top();
        ans = ans < tmp ? tmp : ans;
        return tmp;
    }
    else {
        int tmp1 = pq.top();
        pq.pop();
        int tmp2 = pq.top();
        ans = ans < tmp1 + tmp2 ? tmp1 + tmp2 : ans;
        return tmp1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> u;
        while(true) {
            cin >> v;
            if(v == -1) break;
            cin >> w;
            tree[u].emplace_back(v, w);
        }
    }
    
    int tmp = dfs(1, 0);
    cout << (ans < tmp ? tmp : ans);
    return 0;
}