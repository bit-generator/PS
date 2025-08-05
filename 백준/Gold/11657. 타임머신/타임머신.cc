#include <iostream>
#include <algorithm>
#include <vector>
#define INF    1'000'000'000'000'000'000
using namespace std;

int N, M, A, B, C;
long long graph[501][501];
vector<long long> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i = 1; i <= N; ++i) {
        fill(graph[i] + 1, graph[i] + N + 1, INF);
        graph[i][i] = 0;
    }
    
    while(M--) {
        cin >> A >> B >> C;
        graph[A][B] = min(graph[A][B], (long long)C);
    }
    
    for(int k = 1; k <= N; ++k) {
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                if(graph[i][k] == INF || graph[k][j] == INF) continue;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    
    for(int i = 2; i <= N; ++i) {
        if(graph[1][i] != INF && graph[i][i] < 0LL) {
            cout << -1;
            return 0;
        }
        
        if(graph[1][i] == INF) ans.push_back(-1);
        else ans.push_back(graph[1][i]);
    }
    
    for(auto n : ans) cout << n << '\n';
    return 0;
}