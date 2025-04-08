#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[300001];
long long dp[300001][2];

void dfs(int cur, vector<int>& sales) {
    dp[cur][1] = sales[cur - 1];
    long long zeroadd = 1LL << 32;
    if(graph[cur].size() == 0) return;
    
    bool flag = false;
    
    for(int nxt : graph[cur]) {
        dfs(nxt, sales);

        dp[cur][1] += min(dp[nxt][0], dp[nxt][1]);
        if(dp[nxt][0] > dp[nxt][1]) {
            dp[cur][0] += dp[nxt][1];
            flag = true;
        }
        else {
            dp[cur][0] += dp[nxt][0];
            zeroadd = min(zeroadd, dp[nxt][1] - dp[nxt][0]);
        }
    }
    
    if(!flag) dp[cur][0] += zeroadd;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    for(const auto& v : links) {
        graph[v[0]].push_back(v[1]);
    }
    
    dfs(1, sales);
    return min(dp[1][0], dp[1][1]);
}