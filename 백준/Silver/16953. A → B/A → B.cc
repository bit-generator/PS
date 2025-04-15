#include <iostream>
using namespace std;

int A, B;
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> A >> B;
    
    while(A < B) {
        if(B % 10 != 1) {
            if(B % 2) {
                cout << -1;
                return 0;
            }
            
            B >>= 1;
        }
        else B /= 10;
        ++ans;
    }
    
    if(A == B) cout << ans + 1;
    else cout << -1;
    return 0;
}