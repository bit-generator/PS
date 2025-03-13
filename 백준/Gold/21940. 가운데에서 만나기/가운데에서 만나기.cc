#include <iostream>
#include <vector>
using namespace std;

int N, M, A, B, T, K, C;
int graph[201][201];
int dist[201];
vector<int> ans;
int mn = 1'000'000'000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    while(M--) {
        cin >> A >> B >> T;
        graph[A][B] = T;
    }
    
    for(int k = 1; k <= N; ++k) {
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                if(i == j || !graph[i][k] || !graph[k][j]) continue;
                if(!graph[i][j]) graph[i][j] = graph[i][k] + graph[k][j];
                else graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    
    cin >> K;
    while(K--) {
        cin >> C;
        for(int i = 1; i <= N; ++i) {
            dist[i] = max(dist[i], graph[C][i] + graph[i][C]);
        }
    }
    
    for(int i = 1; i <= N; ++i) {
        if(dist[i] < mn) {
            mn = dist[i];
            ans.clear();
            ans.push_back(i);
        }
        else if(dist[i] == mn) {
            ans.push_back(i);
        }
    }
    
    for(int n : ans) cout << n << ' ';
    return 0;
}