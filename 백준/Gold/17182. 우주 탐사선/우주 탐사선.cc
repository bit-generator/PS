#include <iostream>
#include <algorithm>
using namespace std;

int N, K, ans = 1'000'000'000;
int graph[10][10];
int order[9];
bool check[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> graph[i][j];
        }
    }
    
    for(int k = 0; k < N; ++k) {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(i == j || !graph[i][k] || !graph[k][j]) continue;
                if(!graph[i][j] || graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    
    for(int i = 0, tmp = 0; tmp < N; ++tmp) {
        if(tmp == K) continue;
        order[i++] = tmp;
    }
    
    do {
        int cur = K;
        int dist = 0;
        for(int i = 0; i < N - 1; ++i) {
            dist += graph[cur][order[i]];
            cur = order[i];
        }
        
        if(dist < ans) ans = dist;
    } while(next_permutation(order, order + N - 1));
    
    cout << ans;
    return 0;
}