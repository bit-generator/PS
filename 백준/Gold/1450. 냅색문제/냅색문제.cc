#include <iostream>
#include <map>
using namespace std;

int N, C, ans;
int W[30];
map<int, int> cases, cases2;

void backtrack(int idx, int sum, int M, map<int, int>& m) {
    if(idx >= M) {
        ++m[sum];
        return;
    }
    
    if(sum + W[idx] <= C) {
        backtrack(idx + 1, sum + W[idx], M, m);
    }
    
    backtrack(idx + 1, sum, M, m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> C;
    for(int i = 0; i < N; ++i) cin >> W[i];
    
    backtrack(0, 0, N / 2, cases);
    int sum = 0;
    for(auto& p : cases) {
        sum += p.second;
        cases[p.first] = sum;
    }
    
    backtrack(N / 2, 0, N, cases2);
    for(auto& p : cases2) {
        auto it = cases.upper_bound(C - p.first);
        ans += ((--it)->second * p.second);
    }
    
    cout << ans;
    return 0;
}