#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int N, M, X, Y, K;
vector<pair<int, int>> graph[101];
int indegree[101];
queue<int> q;
int parts[101][101];
bool base[101];
bool check[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    while(M--) {
        cin >> X >> Y >> K;
        graph[Y].emplace_back(X, K);
        ++indegree[X];
    }
    
    for(int i = 1; i < N; ++i) {
        if(indegree[i] == 0) {
            q.push(i);
            check[i] = true;
            base[i] = true;
        }
    }
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if(!check[cur]) {
            for(int i = 1; i < N; ++i) {
                if(!parts[cur][i] || base[i]) continue;
                for(int j = 1; j < N; ++j) {
                    if(base[j]) parts[cur][j] += parts[i][j] * parts[cur][i];
                }
            }
            
            check[cur] = true;
        }
        
        for(const auto& nxt : graph[cur]) {
            parts[nxt.first][cur] += nxt.second;
            if(--indegree[nxt.first] == 0) {
                q.push(nxt.first);
            }
        }
    }
    
    for(int i = 1; i < N; ++i) {
        if(base[i]) cout << i << ' ' << parts[N][i] << '\n';
    }
    return 0;
}