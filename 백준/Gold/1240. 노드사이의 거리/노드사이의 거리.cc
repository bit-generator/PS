#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N, M, A, B, E;
vector<int> graph[1001];
int weight[1001][1001];
int depth[1001];
int parent[1001];

void dfs(int x, int prev) {
    for(int cur : graph[x]) {
        if(cur == prev) continue;
        depth[cur] = depth[x] + 1;
        parent[cur] = x;
        dfs(cur, x);
    }
}

int getDistance(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    
    int ret = 0;
    while(depth[a] != depth[b]) {
        ret += weight[a][parent[a]];        
        a = parent[a];
    }
    
    while(a != b) {
        ret += weight[a][parent[a]];
        ret += weight[b][parent[b]];
        a = parent[a];
        b = parent[b];
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < N - 1; i++) {
        cin >> A >> B >> E;
        graph[A].push_back(B);
        graph[B].push_back(A);
        weight[A][B] = E;
        weight[B][A] = E;
    }
    
    dfs(1, 0);
    
    while(M--) {
        cin >> A >> B;
        cout << getDistance(A, B) << '\n';
    }
    
    return 0;
}