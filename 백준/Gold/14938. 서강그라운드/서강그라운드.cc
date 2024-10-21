#include <iostream>
#include <algorithm>
using namespace std;

int n, m, r, a, b, l, ans;
int t[101];
int edges[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) cin >> t[i];
    while(r--) {
        cin >> a >> b >> l;
        edges[a][b] = l;
        edges[b][a] = l;
    }
    
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;
                if(edges[i][k] != 0 && edges[k][j] != 0) {
                    if(edges[i][j] == 0) edges[i][j] = edges[i][k] + edges[k][j];
                    else edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        int sum = t[i];
        for(int j = 1; j <= n; j++) {
            if(edges[i][j] != 0 && edges[i][j] <= m) sum += t[j];
        }
        
        ans = max(ans, sum);
    }
    
    cout << ans;
    return 0;
}