#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, P, cnt;
int travel[1000];
vector<int> graph[201];
bool check[201];
bool visit[201];
queue<int> q;

void bfs() {
    q.push(travel[0]);
    check[travel[0]] = false;
    visit[travel[0]] = true;
    --cnt;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(const int& nxt : graph[cur]) {
            if(visit[nxt]) continue;
            if(check[nxt]) {
                check[nxt] = false;
                --cnt;
            }
            
            q.push(nxt);
            visit[nxt] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            cin >> P;
            if(P) graph[i].push_back(j);
        }
    }
    
    for(int i = 0; i < M; ++i) {
        cin >> travel[i];
        if(!check[travel[i]]) {
            check[travel[i]] = true;
            ++cnt;
        }
    }
    
    bfs();
    if(!cnt) cout << "YES";
    else cout << "NO";
    return 0;
}