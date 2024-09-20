#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, A, B, maxDist, ans, cnt;
vector<int> graph[20001];
vector<int> visit(20001, -1);

void bfs() {
    queue<int> q;
    q.push(1);
    visit[1] = 0;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int nxt : graph[cur]) {
            if(visit[nxt] == -1) {
                q.push(nxt);
                visit[nxt] = visit[cur] + 1;
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
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    
    bfs();
    
    for(int i = 1; i <= N; i++) {
        if(visit[i] > maxDist) {
            maxDist = visit[i];
            ans = i;
            cnt = 1;
        }
        else if(visit[i] == maxDist) {
            cnt++;
        }
    }
    
    cout << ans << ' ' << visit[ans] << ' ' << cnt;
    return 0;
}