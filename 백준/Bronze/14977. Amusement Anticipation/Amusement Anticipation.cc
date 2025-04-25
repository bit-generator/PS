#include <iostream>
using namespace std;

int N;
int X[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(cin >> N) {
        for(int i = 1; i <= N; ++i) cin >> X[i];
        int ans = 1;
        for(int i = N - 1; i >= 1; --i) {
            if(X[i + 1] - X[i] != X[N] - X[N - 1]) {
                ans = i + 1;
                break;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}