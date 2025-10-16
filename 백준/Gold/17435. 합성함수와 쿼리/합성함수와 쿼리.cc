#include <iostream>
using namespace std;

int m, Q, n, x;
int dp[19][200001];

void fillDP() {
    for(int i = 1; i < 19; ++i) {
        for(int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> m;
    for(int i = 1; i <= m; ++i) cin >> dp[0][i];
    
    fillDP();
    
    cin >> Q;
    while(Q--) {
        cin >> n >> x;
        for(int i = 18; i >= 0; --i) {
            if(n & (1 << i)) x = dp[i][x];
        }
        
        cout << x << '\n';
    }
    
    return 0;
}