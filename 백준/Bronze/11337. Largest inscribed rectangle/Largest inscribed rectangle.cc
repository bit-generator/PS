#include <iostream>
#include <cmath>
using namespace std;

int T, R, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> R >> B;
        B = min(B * B, 2 * R * R);
        R *= R;
        
        long long ans = (long long)B * (4 * R - B);
        cout << fixed;
        cout.precision(3);
        cout << sqrt(ans) << '\n';
    }
    
    return 0;
}