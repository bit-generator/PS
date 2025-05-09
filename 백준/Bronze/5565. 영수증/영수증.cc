#include <iostream>
using namespace std;

int n, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> ans;
    for(int i = 0; i < 9; ++i) {
        cin >> n;
        ans -= n;
    }
    
    cout << ans;
    return 0;
}