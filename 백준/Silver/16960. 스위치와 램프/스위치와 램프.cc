#include <iostream>
#include <vector>
using namespace std;

int N, M, K, L, cnt, ans;
int lamp[2001];
vector<int> sw[2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        cin >> K;
        for(int j = 0; j < K; ++j) {
            cin >> L;
            ++lamp[L];
            sw[i].push_back(L);
        }
    }
    
    for(int i = 1; i <= M; ++i) {
        if(!lamp[L]) {
            cout << 0;
            return 0;
        }
    }
    
    for(int i = 0; i < N; ++i) {
        bool turnoff = false;
        for(int j : sw[i]) {
            if(lamp[j] - 1 == 0) {
                turnoff = true;
                break;
            }
        }
        
        if(!turnoff) ans = 1;
    }
    
    cout << ans;
    return 0;
}