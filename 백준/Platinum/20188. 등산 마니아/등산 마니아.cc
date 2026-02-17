#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N, u, v;
long long ans;
vector<int> graph[300001];
bool visit[300001];

long long dfs(int cur) {
    long long ret = 1;
    for(int nxt : graph[cur]) {
        if(visit[nxt]) continue;
        visit[nxt] = true;
        long long cnt = dfs(nxt);
        if(cnt >= 2) {
            ans += (cnt * (cnt - 1) / 2);
        }
        ans += (cnt * (N - cnt));
        ret += cnt;
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N - 1; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    visit[1] = true;
    dfs(1);
    cout << ans;
    return 0;
}