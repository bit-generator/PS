#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int M, N, L, x, y, ans;
int seat[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> M >> N >> L;
    for(int i = 0; i < M; ++i) cin >> seat[i];
    sort(seat, seat + M);
    
    while(N--) {
        cin >> x >> y;
        auto it = lower_bound(seat, seat + M, x);
        if((it != seat + M && *it - x + y <= L)
           || (it != seat && x - *(--it) + y <= L)) {
            ++ans;
        }
    }
    
    cout << ans;
    return 0;
}