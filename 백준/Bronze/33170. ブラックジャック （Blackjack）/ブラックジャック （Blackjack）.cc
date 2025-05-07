#include <iostream>
using namespace std;

int n, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 3; ++i) {
        cin >> n;
        ans += n;
    }
    
    if(ans <= 21) cout << 1;
    else cout << 0;
    return 0;
}