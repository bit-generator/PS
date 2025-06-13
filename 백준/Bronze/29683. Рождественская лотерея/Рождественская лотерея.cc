#include <iostream>
using namespace std;

int n, A, a, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> A;
    while(n--) {
        cin >> a;
        ans += (a / A);
    }
    
    cout << ans;
    return 0;
}