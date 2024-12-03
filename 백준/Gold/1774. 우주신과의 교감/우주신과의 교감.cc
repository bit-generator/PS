#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M, X, Y;
double ans;
pair<int, int> coord[1001];
vector<tuple<double, int, int>> edges;
int parent[1001];
int urank[1001];

constexpr long long square(long long x) { return x * x; }

double dist(int n1, int n2) { 
    return sqrt(square(coord[n2].first - coord[n1].first)
                + square(coord[n2].second - coord[n1].second));
}

int Find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if(a > b) swap(a, b);
    if(urank[a] == urank[b]) ++urank[a];
    if(urank[a] > urank[b]) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) {
        cin >> coord[i].first >> coord[i].second;
        
        for(int j = 1; j < i; ++j) {
            edges.emplace_back(dist(i, j), j, i);
        }
        
        parent[i] = i;
    }
    
    int cnt = 0;
    while(M--) {
        cin >> X >> Y;
        if(Find(X) == Find(Y)) continue;
        Union(X, Y);
        ++cnt;
    }
    
    sort(edges.begin(), edges.end());
    int i = 0;
    while(cnt < N - 1 && i < edges.size()) {
        int a, b;
        double cost;
        tie(cost, a, b) = edges[i++];
        
        if(Find(a) == Find(b)) continue;
        Union(a, b);
        ans += cost;
        ++cnt;
    }
    
    cout << fixed;
    cout.precision(2);
    cout << ans;
    return 0;
}