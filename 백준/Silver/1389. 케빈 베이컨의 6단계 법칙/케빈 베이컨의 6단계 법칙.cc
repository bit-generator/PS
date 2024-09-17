#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, A, B, minVal = 50000, ans;
bool graph[101][101];
int visit[101];
int bacon[101];

void bfs(int x) {
    queue<int> q;
    q.push(x);
    visit[x] = 0;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int i = 1; i <= N; i++) {
            if(graph[cur][i] && visit[i] == -1) {
                q.push(i);
                visit[i] = visit[cur] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    while(M--) {
        cin >> A >> B;
        graph[A][B] = 1;
        graph[B][A] = 1;
    }
    
    for(int i = 1; i <= N; i++) {
        memset(visit + 1, -1, sizeof(int) * N);
        bfs(i);
        
        for(int j = 1; j <= N; j++) {
            bacon[i] += visit[j];
        }
        
        if(bacon[i] < minVal) {
            minVal = bacon[i];
            ans = i;
        }
    }
    
    cout << ans;
    return 0;
}