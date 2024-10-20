#include <iostream>
#include <vector>
using namespace std;

int n, a, b, m, x, y, ans = -1;
bool found = false;
vector<int> graph[101];

void dfs(int cur, int prv, int cnt) {
    for(int nxt : graph[cur]) {
        if(nxt == prv) continue;
        if(nxt == b) {
            ans = cnt + 1;
            found = true;
            return;
        }
        dfs(nxt, cur, cnt + 1);
        if(found) return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> a >> b >> m;
    while(m--) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    dfs(a, 0, 0);
    cout << ans;
    return 0;
}