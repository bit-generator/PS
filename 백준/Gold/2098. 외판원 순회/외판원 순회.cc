#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

constexpr size_t SIZE = 1 << 16;
constexpr size_t INF = 100'000'000;
int N;
int graph[16][16];
int dp[SIZE][16];

int tsp(int mask, int node) {
    if(mask == (1 << N) - 1) {
        if(graph[node][0] == 0) return INF;
        else return graph[node][0];
    }
    
    if(dp[mask][node] != -1) return dp[mask][node];
    
    dp[mask][node] = INF;
    for(int i = 1; i < N; ++i) {
        if(graph[node][i] == 0) continue;
        if(mask & (1 << i)) continue;
        
        dp[mask][node] = min(dp[mask][node], graph[node][i] + tsp(mask | (1 << i), i));
    }
    
    return dp[mask][node];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> graph[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    cout << tsp(1, 0);
    return 0;
}