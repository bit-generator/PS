#include <iostream>
using namespace std;

int N, a, b;
int ans[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> a >> b;
    if(a + b > N + 1) {
        cout << -1;
        return 0;
    }
    
    if(a >= b) {
        for(int i = 0; i < a; ++i) {
            ans[N - b - i] = a - i;
        }
        
        for(int i = 1; i < b; ++i) {
            ans[N - i] = i;
        }
        
        for(int i = 0; i <= N - b - a; ++i) {
            ans[i] = 1;
        }
    }
    else {
        if(a == 1) {
            for(int i = 1; i < b; ++i) {
                ans[N - i] = i;
            }
            ans[0] = b;
            
            for(int i = 1; i <= N - b; ++i) {
                ans[i] = 1;
            }
        }
        else {
            for(int i = 1; i <= b; ++i) {
                ans[N - i] = i;
            }
        
            for(int i = 1; i < a; ++i) {
                ans[N - b - a + i] = i;
            }
        
            for(int i = 0; i <= N - b - a; ++i) {
                ans[i] = 1;
            }
        }
    }
    
    for(int i = 0; i < N; ++i) cout << ans[i] << ' ';
    return 0;
}