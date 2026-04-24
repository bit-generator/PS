#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
using namespace std;

int N, W;
pair<int, int> cases[2][1001];
int dp[1001][1001];

inline int dist(const pair<int, int>& p1, const pair<int, int>& p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int solve(int pidx1, int pidx2) {
    if(pidx1 == W || pidx2 == W) return 0;
    if(dp[pidx1][pidx2] != -1) return dp[pidx1][pidx2];
    
    int nextIdx = max(pidx1, pidx2) + 1;
    int dist1 = dist(cases[0][pidx1], cases[0][nextIdx]) + solve(nextIdx, pidx2);
    int dist2 = dist(cases[1][pidx2], cases[1][nextIdx]) + solve(pidx1, nextIdx);
    return dp[pidx1][pidx2] = min(dist1, dist2);
}

void chase(int pidx1, int pidx2) {
    if(pidx1 == W || pidx2 == W) return;
    
    int nextIdx = max(pidx1, pidx2) + 1;
    int dist1 = dist(cases[0][pidx1], cases[0][nextIdx]) + dp[nextIdx][pidx2];
    int dist2 = dist(cases[1][pidx2], cases[1][nextIdx]) + dp[pidx1][nextIdx];
    if(dist1 < dist2) {
        cout << 1 << '\n';
        chase(nextIdx, pidx2);
    }
    else {
        cout << 2 << '\n';
        chase(pidx1, nextIdx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> W;
    for(int i = 1; i <= W; ++i) {
        cin >> cases[0][i].first >> cases[0][i].second;
        cases[1][i] = cases[0][i];
    }
    
    cases[0][0] = {1, 1};
    cases[1][0] = {N, N};
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << '\n';
    chase(0, 0);
    return 0;
}