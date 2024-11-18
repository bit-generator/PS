#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M, P, ans = 1000000;
vector<int> graph[11];
int population[11];
bool team[11];
bool visit[11];

int bfs(int x, int cnt, int color) {
    queue<int> q;
    memset(visit, 0, sizeof(visit));
    q.push(x);
    visit[x] = true;
    int teamCnt = 0;
    int total = 0;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        ++teamCnt;
        total += population[cur];
        
        for(int nxt : graph[cur]) {
            if(team[nxt] != color || visit[nxt]) continue;
            visit[nxt] = true;
            q.push(nxt);
        }
    }
    
    if(teamCnt == cnt) return total;
    else return -1;
}

void divide(int cnt) {
    int idxA, idxB;
    for(int i = 1; i <= N; i++) {
        if(team[i] == 1) idxA = i;
        else idxB = i;
    }
    
    int A = bfs(idxA, cnt, 1);
    int B = bfs(idxB, N - cnt, 0);
    if(A == -1 || B == -1) return;
    ans = min(ans, abs(A - B));
}

void backtrack(int cnt, int n, int prev) {
    if(cnt == n) {
        divide(n);
        return;
    }
    
    for(int i = 1; i <= N; i++) {
        if(i <= prev) continue;
        team[i] = 1;
        backtrack(cnt + 1, n, i);
        team[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> population[i];
    }
    
    for(int i = 1; i <= N; i++) {
        cin >> M;
        while(M--) {
            cin >> P;
            graph[i].push_back(P);
        }
    }
    
    for(int i = 1; i <= N / 2; i++) {
        backtrack(0, i, -1);
    }
    
    
    if(ans == 1000000) cout << -1;
    else cout << ans;
    return 0;
}