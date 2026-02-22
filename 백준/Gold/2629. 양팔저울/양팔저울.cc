#include <iostream>
using namespace std;

int N, M, weight, marble;
bool dp[40001][31];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    dp[0][0] = true;
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        cin >> weight;
        for(int j = 0; j <= 40000; ++j) {
            dp[j][i] = dp[j][i - 1];
            if(j < weight && dp[weight - j][i - 1]) dp[j][i] = true;
            if(j >= weight && dp[j - weight][i - 1]) dp[j][i] = true;
            if(j + weight <= 40000 && dp[j + weight][i - 1]) dp[j][i] = true;
        }
    }
    
    cin >> M;
    while(M--) {
        cin >> marble;
        if(dp[marble][N]) cout << 'Y';
        else cout << 'N';
        cout << ' ';
    }
    
    return 0;
}