#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int T, N, K, X, Y, W;
int times[1001];
int takes[1001];
vector<int> graph[1001];
int indegree[1001];
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> N >> K;
        for(int i = 1; i <= N; ++i) cin >> times[i];
        for(int i = 1; i <= N; ++i) graph[i].clear();
        memset(indegree, 0, sizeof(int) * (N + 1));
        memset(takes, 0, sizeof(int) * (N + 1));
        while(K--) {
            cin >> X >> Y;
            graph[X].push_back(Y);
            ++indegree[Y];
        }
        cin >> W;
        
        for(int i = 1; i <= N; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
                takes[i] = times[i];
            }
        }
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for(int nxt : graph[cur]) {
                takes[nxt] = max(takes[nxt], times[nxt] + takes[cur]);
                if(--indegree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }
        
        cout << takes[W] << '\n';
    }
    
    return 0;
}