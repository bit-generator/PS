#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N, M, times, P, ans;
int indegree[10001];
int dp[10001];
int nodetime[10001];
vector<int> graph[10001];
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        cin >> times >> M;
        nodetime[i] = times;
        indegree[i] = M;
        if(M == 0) {
            q.push(i);
            dp[i] = times;
            ans = max(ans, dp[i]);
        }
        
        while(M--) {
            cin >> P;
            graph[P].push_back(i);
        }
    }
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(const int& n : graph[cur]) {
            dp[n] = max(dp[n], dp[cur] + nodetime[n]);
            ans = max(ans, dp[n]);
            if(--indegree[n] == 0) {
                q.push(n);
            }
        }
    }
    
    cout << ans;
    return 0;
}