#include <iostream>
using namespace std;

int m, n, k;
int customer[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true) {
        cin >> m >> n;
        if(m == 0 && n == 0) break;
        
        for(int i = 0; i < m; ++i) cin >> customer[i];
        
        int ans = 0;
        
        for(int i = 0; i < n; ++i) {
            bool matched = true;
            
            for(int j = 0; j < m; ++j) {
                cin >> k;
                if(customer[j] < k) {
                    matched = false;
                }
            }
            
            if(matched) ++ans;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}