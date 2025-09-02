#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int sum;
queue<pair<int, int>> q;
bool visit[1001][1001];
int cur[3], nxt[3];

int bfs() {
    if(cur[0] == cur[1] && cur[1] == cur[2]) return 1;
    
    sort(cur, cur + 3);
    q.emplace(cur[0], cur[1]);
    visit[cur[0]][cur[1]] = true;
    
    while(!q.empty()) {
        cur[0] = q.front().first;
        cur[1] = q.front().second;
        cur[2] = sum - cur[0] - cur[1];
        q.pop();
        
        for(int i = 0; i < 2; ++i) {
            for(int j = i + 1; j < 3; ++j) {
                nxt[0] = cur[i] << 1;
                nxt[1] = cur[j] - cur[i];
                nxt[2] = cur[3 - i - j];
                sort(nxt, nxt + 3);
                
                if(visit[nxt[0]][nxt[1]]) continue;
                if(nxt[0] == nxt[1] && nxt[1] == nxt[2]) return 1;
                q.emplace(nxt[0], nxt[1]);
                visit[nxt[0]][nxt[1]] = true;
            }
        }
    }
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 3; ++i) {
        cin >> cur[i];
        sum += cur[i];
    }
    
    cout << bfs();
    return 0;
}