#include <iostream>
using namespace std;

int cnt[10] = {1, 0, 0, 1, 0, 0, 1, 0, 0, 0};
int totalCnt[200000];
int N, Q, X, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> Q;
    for(int i = 0; i < N; ++i) {
        totalCnt[i] = cnt[i % 10];
        ans += cnt[i % 10];
    }
    
    while(Q--) {
        cin >> X;
        if(totalCnt[X - 1]) {
            totalCnt[X - 1] = 0;
            --ans;
        }
        else {
            totalCnt[X - 1] = 1;
            ++ans;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}