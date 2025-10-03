#include <iostream>
using namespace std;

int G, P, ans;
int g[100000];
int parent[100001];

int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> G >> P;
    for(int i = 0; i < P; ++i) {
        cin >> g[i];
    }
    
    for(int i = 1; i <= G; ++i) parent[i] = i;
    
    for(int i = 0; i < P; ++i) {
        int pos = find(g[i]);
        if(pos == 0) break;
        Union(pos - 1, pos);
        ++ans;
    }
    
    cout << ans;
    return 0;
}