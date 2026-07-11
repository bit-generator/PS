#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<pair<int, int>> graph[101];
int N, src, K, ans;
int order[10];

void bfs() {
    queue<int> q;
    bool visit[101] = {false};
    int cnt = 1;
    visit[src] = true;
    
    for(int i = 0; i < K; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(visit[j]) q.push(j);
        }

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(auto& p : graph[cur]) {
                int nxt = p.first;
                int pipe = p.second;

                if(visit[nxt]) continue;
                if(pipe == order[i]) {
                    visit[nxt] = true;
                    q.push(nxt);
                    ++cnt;
                }
            }
        }
    }
    
    ans = max(ans, cnt);
}

void backtrack(int cur) {
    if(cur == K) {
        bfs();
        return;
    }
    
    for(int i = 1; i <= 3; ++i) {
        if(cur > 0 && order[cur - 1] == i) continue;
        
        order[cur] = i;
        backtrack(cur + 1);
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    N = n, K = k;
    src = infection;
    
    // 그래프 만들기
    for(auto& v : edges) {
        int n1 = v[0], n2 = v[1], type = v[2];
        graph[n1].emplace_back(n2, type);
        graph[n2].emplace_back(n1, type);
    }
    
    backtrack(0);
    return ans;
}