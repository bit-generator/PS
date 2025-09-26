#include <iostream>
using namespace std;

int n, m, q, a, b;
int parent[1000001];
int urank[1000001];

int find(int x) {
    if(x == parent[x]) return x;
    return x = find(parent[x]);
}

void Union() {
    int x = find(a);
    int y = find(b);
    if(urank[x] == urank[y]) ++urank[x];
    if(urank[x] > urank[y]) parent[y] = x;
    else parent[x] = y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) parent[i] = i;
    
    while(m--) {
        cin >> q >> a >> b;
        if(q) {
            if(find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            Union();
        }
    }
    
    return 0;
}