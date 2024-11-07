#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int N, M, A, B, C, ans;
vector<tuple<int, int, int>> edges;
int parent[100001], urank[100001];

int find(int x) {
    if(x == parent[x]) return x;
    else return x = find(parent[x]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(urank[a] == urank[b]) urank[a]++;
    if(urank[a] > urank[b]) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    while(M--) {
        cin >> A >> B >> C;
        edges.emplace_back(C, A, B);
    }
    sort(edges.begin(), edges.end());
    
    for(int i = 1; i <= N; i++) parent[i] = i;
    int cnt = 0;
    for(auto tp : edges) {
        if(cnt == N - 2) break;
        int a, b, cost;
        tie(cost, a, b) = tp;
        if(find(a) == find(b)) continue;
        
        Union(a, b);
        ans += cost;
        cnt++;
    }
    
    cout << ans;
    return 0;
}