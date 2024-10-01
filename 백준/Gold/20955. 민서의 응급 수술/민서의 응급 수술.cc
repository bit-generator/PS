#include <iostream>
#include <vector>
using namespace std;

int N, M, u, v, ans, cnt;
pair<int, int> edges[100000];
int parent[100001];

int find(int x) {
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b); 
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> u >> v;
        edges[i] = {u, v};
    }
    
    for(int i = 1; i <= N; i++) parent[i] = i;
    
    for(int i = 0; i < M; i++) {
        int a = edges[i].first;
        int b = edges[i].second;
        if(find(a) == find(b)) {
            ans++;
            continue;
        }
        
        Union(a, b);
        cnt++;
    }
    
    cout << ans + (N - 1 - cnt);
    return 0;
}