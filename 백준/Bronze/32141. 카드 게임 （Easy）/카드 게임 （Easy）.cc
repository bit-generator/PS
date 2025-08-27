#include <iostream>
using namespace std;

int N, H, d, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> H;
    while(N--) {
        cin >> d;
        H -= d;
        ++ans;
        if(H <= 0) break;
    }
    
    if(H <= 0) cout << ans;
    else cout << -1;
    return 0;
}