#include <iostream>
using namespace std;

int N;
long long ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i < N; ++i) {
        ans += ((long long)i * N + i);
    }
    
    cout << ans;
    return 0;
}