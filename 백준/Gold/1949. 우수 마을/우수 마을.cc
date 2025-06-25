#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, A, B;
vector<int> graph[10001];
int dp[10001][2];
bool check[10001];

void dfs(int cur) {
    for(int nxt : graph[cur]) {
        if(check[nxt]) continue;
        check[nxt] = true;
        dfs(nxt);
        check[nxt] = false;
        
        dp[cur][0] += max(dp[nxt][0], dp[nxt][1]);
        dp[cur][1] += dp[nxt][0];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> dp[i][1];
    for(int i = 0; i < N - 1; ++i) {
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    
    check[1] = true;
    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
    return 0;
}