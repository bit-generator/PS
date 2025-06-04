#include <iostream>
#include <algorithm>
using namespace std;

int N, Q, C, s, e;
int graph[302][301][301];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> Q;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            cin >> graph[1][i][j];
        }
    }
    
    for(int k = 1; k <= N; ++k) {
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                if(i == j || !graph[i][k] || !graph[k][j]) {
                    graph[k + 1][i][j] = graph[k][i][j];
                    continue;
                }
                
                if(!graph[k][i][j]) graph[k + 1][i][j] = graph[k][i][k] + graph[k][k][j];
                else graph[k + 1][i][j] = min(graph[k][i][j], graph[k][i][k] + graph[k][k][j]);
            }
        }
    }
    
    while(Q--) {
        cin >> C >> s >> e;
        if(graph[C][s][e] || s == e) cout << graph[C][s][e] << '\n';
        else cout << -1 << '\n';
    }
    
    return 0;
}