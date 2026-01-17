#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int N, M, L, K, ans;
pair<int, int> stars[100];

int solve(int x, int y) {
    int ret = 0;
    for(int i = 0; i < K; ++i) {
        if(x <= stars[i].first && stars[i].first <= x + L
           && y <= stars[i].second && stars[i].second <= y + L)
            ++ret;
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> L >> K;
    for(int i = 0; i < K; ++i) {
        cin >> stars[i].first >> stars[i].second;
    }
    
    if(K == 1) {
        cout << 0;
        return 0;
    }
    
    ans = K;
    for(int i = 0; i < K - 1; ++i) {
        for(int j = i + 1; j < K; ++j) {
            int x = min(stars[i].first, stars[j].first);
            int y = min(stars[i].second, stars[j].second);
            
            ans = min(ans, K - solve(x, y));
        }
    }
    
    cout << ans;
    return 0;
}