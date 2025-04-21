#include <iostream>
#include <algorithm>
using namespace std;

int N, M, T, u, v, h, s, e;
int graph[301][301];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> T;
    while(M--) {
        cin >> u >> v >> h;
        graph[u][v] = h;
    }
    
    for(int k = 1; k <= N; ++k) {
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                if(i == j || !graph[i][k] || !graph[k][j]) continue;
                if(!graph[i][j]) graph[i][j] = max(graph[i][k], graph[k][j]);
                else graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));
            }
        }
    }
    
    while(T--) {
        cin >> s >> e;
        if(!graph[s][e]) cout << -1 << '\n';
        else cout << graph[s][e] << '\n';
    }
    
    return 0;
}