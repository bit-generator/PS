#include <iostream>
using namespace std;

int M, X, Y, ans = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> M;
    while(M--) {
        cin >> X >> Y;
        if(ans == X) {
            ans = Y;
        }
        else if(ans == Y) {
            ans = X;
        }
    }
    
    cout << ans;
    return 0;
}