#include <iostream>
using namespace std;

int n, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 5; ++i) {
        cin >> n;
        if(n >= 40) ans += n;
        else ans += 40;
    }
    
    cout << ans / 5;
    return 0;
}