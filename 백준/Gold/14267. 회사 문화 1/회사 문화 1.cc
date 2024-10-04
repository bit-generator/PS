#include <iostream>
#include <vector>
using namespace std;

int n, m, u, w;
vector<int> graph[100001];
int score[100001];

void dfs(int cur, int prev) {
    for(int nxt : graph[cur]) {
        if(nxt == prev) continue;
        score[nxt] += score[cur];
        dfs(nxt, cur);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    int tmp;
    cin >> tmp;
    
    for(int i = 2; i <= n; i++) {
        cin >> tmp;
        graph[tmp].push_back(i);
    }
    
    while(m--) {
        cin >> u >> w;
        score[u] += w;
    }
    
    dfs(1, 0);
    for(int i = 1; i <= n; i++) {
        cout << score[i] << ' ';
    }
    return 0;
}