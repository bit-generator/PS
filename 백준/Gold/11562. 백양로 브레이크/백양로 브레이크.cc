#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, u, v, b, k, s, e;
int graph[251][251];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(graph, -1, sizeof(graph));
    
    cin >> n >> m;
    while(m--) {
        cin >> u >> v >> b;
        if(b) {
            graph[u][v] = 0;
            graph[v][u] = 0;
        }
        else {
            graph[u][v] = 0;
            graph[v][u] = 1;
        }
    }
    
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(i == j) {
                    graph[i][j] = 0;
                    continue;
                }
                if(graph[i][k] == -1 || graph[k][j] == -1) continue;
                
                if(graph[i][j] == -1) graph[i][j] = graph[i][k] + graph[k][j];
                else graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    
    cin >> k;
    while(k--) {
        cin >> s >> e;
        cout << graph[s][e] << '\n';
    }
    
    return 0;
}