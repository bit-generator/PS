#include <iostream>
#include <utility>
using namespace std;

int n, m, ans;
pair<int, int> points[1000000];
int parent[500000];
int urank[500000];

int find(int x) {
    if(parent[x] == x) return x;
    return x = find(parent[x]);
}

void Union(int a, int b) {
    if(urank[a] == urank[b]) ++urank[a];
    if(urank[a] > urank[b]) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        parent[i] = i;
    
    for(int i = 0; i < m; ++i)
        cin >> points[i].first >> points[i].second;
    
    for(int i = 0; i < m; ++i) {
        int a = find(points[i].first);
        int b = find(points[i].second);
        if(a == b) {
            ans = i + 1;
            break;
        }
        
        Union(a, b);
    }
    
    cout << ans;
    return 0;
}