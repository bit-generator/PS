#include <iostream>
using namespace std;

int N, complement, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    complement = ~N + 1;
    N ^= complement;
    
    for(int i = 0; i < 32; ++i) {
        if(N & (1 << i)) ++ans;
    }
    
    cout << ans;
    return 0;
}