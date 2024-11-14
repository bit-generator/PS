#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, A, B, C, good, worst;
vector<tuple<int, int, int>> edges;
int parent[1001], urank[1001];

int find(int x) {
    if(x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
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
    cin >> A >> B >> C;
    if(!C) {
        good++; worst++;
    }
    
    while(M--) {
        cin >> A >> B >> C;
        edges.emplace_back(C, A, B);
    }
    sort(edges.begin(), edges.end());
    
    for(int i = 1; i <= N; i++) parent[i] = i;
    int cnt = 0;
    int sz = edges.size();
    for(int i = 0; i < sz; i++) {
        int a, b, cost;
        tie(cost, a, b) = edges[i];
        if(find(a) == find(b)) continue;
        
        Union(a, b);
        worst += !cost;
        if(++cnt == N - 1) break;
    }
    
    for(int i = 1; i <= N; i++) parent[i] = i;
    memset(urank, 0, sizeof(int) * (N + 1));
    cnt = 0;
    for(int i = sz - 1; i >= 0; i--) {
        int a, b, cost;
        tie(cost, a, b) = edges[i];
        if(find(a) == find(b)) continue;
        
        Union(a, b);
        good += !cost;
        if(++cnt == N - 1) break;
    }
    
    cout << worst * worst - good * good;
    return 0;
}