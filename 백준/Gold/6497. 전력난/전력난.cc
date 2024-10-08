#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int m, n, x, y, z, totalDist;
vector<tuple<int, int, int>> edges;
int parent[200000];

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
    
    while(true) {
        cin >> m >> n;
        if(m == 0 && n == 0) break;
        
        totalDist = 0;
        edges.clear();
        
        while(n--) {
            cin >> x >> y >> z;
            edges.emplace_back(z, x, y);
            totalDist += z;
        }
        
        sort(edges.begin(), edges.end());
        for(int i = 0; i < m; i++) parent[i] = i;
        
        int sum = 0, cnt = 0;
        for(auto tp : edges) {
            int a, b, cost;
            tie(cost, a, b) = tp;
            if(find(a) == find(b)) continue;
            
            Union(a, b);
            sum += cost;
            if(++cnt == m - 1) break;
        }
        
        cout << totalDist - sum << '\n';
    }
    
    return 0;
}